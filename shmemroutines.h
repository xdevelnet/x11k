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

#ifndef X11K_SHMEMROUTINES_H
#define X11K_SHMEMROUTINES_H

#include <sys/shm.h>

int shmid = -1;

void *attach_or_die(int id) {
	void *shmem = shmat(id, NULL, 0);
	if (shmem == (char *) (-1)) {
		perror("Failed to attach shared memory");
		exit(EXIT_FAILURE);
	}
	return shmem;
}

void remove_shmem() {
	if (shmid != -1) shmctl(shmid, IPC_RMID, NULL);
}

void *takemem() {
	if ((shmid = shmget(SHMEM_KEY, sizeof(pid_t), 0644 | IPC_CREAT)) < 0) {
		perror("Unable to obtain shared memory segment");
		exit(EXIT_FAILURE);
	}
	return attach_or_die(shmid);
}

int check_if_shmem_not_exist() {
	//returns -1 if exist and non-negative value if not exist
	//non-negative val means that shmem is created and ready to use
	int shmemid = shmget(SHMEM_KEY, sizeof(pid_t), 0644 | IPC_CREAT | IPC_EXCL);
	if (shmemid < 0) {
		if (errno != EEXIST) {
			perror("Unable to obtain shared memory segment");
			exit(EXIT_FAILURE);
		} else {
			return -1;
		}
	} else {
		return shmemid;
	}
}

void check_and_update_shmem(pid_t newpid) {
	pid_t *cpid = NULL;
	if ((shmid = check_if_shmem_not_exist()) < 0) {
		cpid = (pid_t *) takemem();
		if (*cpid > 10 and kill(*cpid, 0) == 0) {
			fprintf(stderr, "Another instance of program is already running at pid: %d. Exiting.\n", *cpid);
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "Previous process was not ended correctly. Starting...\n");
		}
	}
	if (cpid == NULL) cpid = (pid_t *) attach_or_die(shmid);
	*cpid = newpid;
}

void check_rc_d_commands(char *command, int *mode) { // This shit may be rewritten from scratch... But I don't even care. Sorry.
	pid_t *cpid;
	if (strcmp(command, "status") == 0) {
		if ((shmid = check_if_shmem_not_exist()) >= 0) {
			fprintf(stderr, "Program is not running.\n");
			remove_shmem();
			exit(EXIT_SUCCESS);
		}
		cpid = (pid_t *) takemem();
		if (kill(*cpid, 0) == 0) {
			fprintf(stderr, "Program is running at pid %u.\n", *cpid);
		} else {
			fprintf(stderr, "Program is not running.\n");
		}
		exit(EXIT_SUCCESS);
	} else																																																										if (strcmp(command, "yoba") == 0) printf("%s", yoba); else
	if (strcmp(command, "start") == 0) *mode = MODE_BACKGROUND; else
	if (strcmp(command, "stop") == 0) { // YAY! COPYPASTING AGAIN! I LOVE MYSELF (NO)
		if ((shmid = check_if_shmem_not_exist()) >= 0) {
			fprintf(stderr, "Program is not running. Nothing to stop.\n");
			remove_shmem();
			exit(EXIT_SUCCESS);
		}
		cpid = (pid_t *) takemem();
		if (kill(*cpid, 0) == 0) {
			if (kill(*cpid, SIGTERM) < 0) {
				perror("Unable to kill process");
				exit(EXIT_FAILURE);
			} else {
				fprintf(stderr, "Stopped.\n");
				exit(EXIT_SUCCESS);
			}
		} else {
			fprintf(stderr, "Program is not running.\n");
		}
		exit(EXIT_SUCCESS);
	}
}

#endif
