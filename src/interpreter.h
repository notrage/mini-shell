#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "csapp.h"
#include "error.h"
#include "global.h"
#include "readcmd.h"

#define FG 0
#define BG 1

void pipes_handling(int **pipes, int nb_pipes, int rank);

void exec_cmd_line(struct cmdline *cmd_line);

#endif // INTERPRETER_H