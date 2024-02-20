/*
 * Copyright (C) 2002, Simon Nieuviarts
 */

#include "csapp.h"
#include "readcmd.h"
#include "handlers.h"
#include "interpreter.h"

int main()
{
	fg_list = create_list();
	bg_list = create_list();
	Signal (SIGCHLD, sigchild_handler);

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