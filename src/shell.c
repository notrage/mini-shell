/*
 * Copyright (C) 2002, Simon Nieuviarts
 */

#include "csapp.h"
#include "global.h"
#include "readcmd.h"
#include "handlers.h"
#include "interpreter.h"

int main()
{
	// initialize the lists
	fg_list = create_list();
	bg_list = create_list();
	// redirect the signals to the handlers
	Signal (SIGCHLD, sigchild_handler);
	Signal (SIGINT, parent_sigint_handler);

	struct cmdline *l = NULL;

	do {
		// giving the prompt
		printf("MINI-SHELL > ");
		// read command line
		l = readcmd();
		// interpret command line
		cmd_intern_extern(l);
	
	} while (l);

	return 0;
}