#include "error.h"

void exec_error(char *cmd) {
    fprintf(stderr, "%s: command not found\n", cmd);
    return;
}

void open_error(char *file) {
    fprintf(stderr, "%s: permission denied\n", file);
    return;
}

void cmd_line_error(char *cmd) {
    fprintf(stderr, "error: %s\n", cmd);
    return;
}