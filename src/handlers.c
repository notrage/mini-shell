#include "handlers.h"

void sigchild_handler(int sig) {
    
    pid_t pid = wait(NULL);

    if (!remove_from_list(fg_list, pid)) 
        remove_from_list(bg_list, pid);

    return;
}