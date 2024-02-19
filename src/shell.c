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
		printf("MINI-SHELL > ");
		l = readcmd();
		exec_cmd_line(l);
	}
	
	return 0;
}