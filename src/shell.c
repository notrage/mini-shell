/*
 * Copyright (C) 2002, Simon Nieuviarts
 */

#include "csapp.h"
#include "shell.h"
#include "readcmd.h"
#include "interpreter.h"

int main()
{
	while (1)
	{
		struct cmdline *l;
		printf("PUM-TZIN > ");
		l = readcmd();

		if (l == NULL)
		{
			printf("Bye\n");
			exit(0);
		}

		exec_cmd_line(l);

		// int fd[2];
		// pipe(fd);
		// int pid;
		// for (int i = 0; i < 2; i++) {
		// 	if ((pid = Fork()) == 0) {// fils

		// 		execvp(l->seq[i][0], l->seq[i]);
		// 		fprintf(stderr, "Command not found\n");
		// 		exit(1);
		// 	}
		// 	else 
		// 	{
		// 	}
		// }
		// exit(0);
	}
	
	
	return 0;
}