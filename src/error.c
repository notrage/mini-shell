#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void fork_error(char *cmd) {
    fprintf(stderr, "%s: fork failed\n", cmd);
    return;
}

void exec_error(char *cmd) {
    fprintf(stderr, "%s: command not found\n", cmd);
    return;
}

void open_error(char *file) {
    fprintf(stderr, "%s: permission denied\n", file);
    return;
}

void cmd_line_error(char *error) {
    fprintf(stderr, "error: %s\n", error);
    return;
}