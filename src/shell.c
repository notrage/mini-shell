/*
 * Copyright (C) 2002, Simon Nieuviarts
 */

#include <stdio.h>
#include <stdlib.h>
#include "readcmd.h"
#include "csapp.h"
#include "shell.h"
#include "cmd_intern.h"
#include "cmd_extern.h"

int main()
{
	while (1)
	{
		struct cmdline *l;
		int i;

		printf("$> ");
		l = readcmd();

		if (l->err)
		{
			/* Syntax error, read another command */
			printf("error: %s\n", l->err);
			continue;
		}

		if (l->in)
			printf("in: %s\n", l->in);
		if (l->out)
			printf("out: %s\n", l->out);

		/* Display each command of the pipe */
		for (i = 0; l->seq[i] != 0; i++)
		{
			char **cmd = l->seq[i];
			if (is_cmd_intern(cmd))
				exec_cmd_intern(cmd);
			else
				exec_cmd_extern(cmd, l->in, l->out);
			printf("\n");
		}
	}
}

int is_cmd_intern(char **cmd) {
	char *exec = cmd[0];
	if (!strcmp(exec, "cd") || !strcmp(exec, "quit"))
		return 1;
	else
		return 0;
}