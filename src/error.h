#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

void fork_error(char *cmd);

void exec_error(char *cmd);

void open_error(char *file);

void cmd_line_error(char *error);

#endif // ERROR_H