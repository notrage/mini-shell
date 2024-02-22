#include "internal_cmd.h"

void quit() {
    exit(0);
}

void cd(char *path) {
    chdir(path);
    printf("Changed current directory to %s\n", path);
    return;
}
