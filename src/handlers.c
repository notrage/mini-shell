#include "handlers.h"

void sigchild_handler(int sig) {
    
    pid_t pid = wait(NULL);

    if (!remove_from_list(fg_list, pid)) 
         remove_from_list(bg_list, pid);

    return;
}

void parent_sigint_handler(int sig) {
    fprintf(stderr, " detected !\n");
    fprintf(stderr, "killing all sub-process !\n");
    fprintf(stderr, "PUM-TZIN > ");
    return;
}