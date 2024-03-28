#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief print a simple error message when an exec failed.
 * @param cmd the failed command
 * @return void
*/
void exec_error(char *cmd);

/**
 * @brief print a simple error message when open function failed.
 * @param file file that failed to open
 * @return void
*/
void open_error(char *file);

/**
 * @brief print a simple error message if there was an error during a command execution.
 * @param cmd error raised during the execution of the command
 * @return void
*/
void cmd_line_error(char *cmd);

#endif // ERROR_H