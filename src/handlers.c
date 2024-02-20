#include "handlers.h"

void sigchild_handler(int sig) {
    
    fprintf(stderr, "SIGCHILD received\n");
    pid_t pid = wait(NULL);

    print_list(fg_list);
    print_list(bg_list);

    if (!remove_from_list(fg_list, pid)) {
        fprintf(stderr, "A signal got excluded from fg list\n");
    } else {
        remove_from_list(bg_list, pid);
        fprintf(stderr, "A signal got excluded from bg list\n");
    }

    print_list(fg_list);
    print_list(bg_list);

    return;
}