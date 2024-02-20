/*
 * Copyright (C) 2002, Simon Nieuviarts
 */

#include "csapp.h"
#include "shell.h"
#include "readcmd.h"
#include "interpreter.h"

int main()
{
	struct cmdline *l = NULL;

	do {
		// giving the prompt
		printf("PUM-TZIN > ");
		// read command line
		l = readcmd();
		// interpret command line
		exec_cmd_line(l);
	
	} while (l);

	return 0;
}