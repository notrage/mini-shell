#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "csapp.h"
#include "error.h"
#include "global.h"
#include "readcmd.h"
#include "internal_cmd.h"

#define FG 0
#define BG 1

/**
 * @brief handles the redirection and closing of pipes for one command.
 * @param pipes array of pipes
 * @param nb_pipes number of pipes
 * @param rank rank of the current command in the command line, to know which pipe to close and 
 *        what redirections to make.
 * @return void
*/
void pipes_handling(int **pipes, int nb_pipes, int rank);

/**
 * @brief handles the execution of the command line received as parameter.
 * @param cmd_line structure cmdline containing a sequence of command, the mode with which they should be launch 
 *        (foreground or background) and potential intput / output redirections and/or error messages.
 * @return void
*/
void exec_cmd_line(struct cmdline *cmd_line);

#endif // INTERPRETER_H