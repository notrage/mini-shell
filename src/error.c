#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void fork_error(char *cmd) {
    fprintf(stderr, "%s: fork failed\n", cmd);
    exit(1);
    return;
}

void exec_error(char *cmd) {
    fprintf(stderr, "%s: command not found\n", cmd);
    exit(1);
    return;
}

void open_error(char *file) {
    fprintf(stderr, "%s: permission denied\n", file);
    exit(1);
    return;
}

