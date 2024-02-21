#include "error.h"

/**
 * @fn exec_error
 * @brief print a simple error message when an exec failed.
 * @param cmd command name of failed command
 * @return void
*/
void exec_error(char *cmd) {
    fprintf(stderr, "%s: command not found\n", cmd);
    return;
}

/**
 * @fn open_error
 * @brief print a simple error message when open function failed.
 * @param file file that failed to open
 * @return void
*/
void open_error(char *file) {
    fprintf(stderr, "%s: permission denied\n", file);
    return;
}

/**
 * @fn cmd_line_error
 * @brief print a simple error message if there was an error during the reading of the command by the readline function.
 * @param error error raised during the reading of the command
 * @return void
*/
void cmd_line_error(char *error) {
    fprintf(stderr, "error: %s\n", error);
    return;
}