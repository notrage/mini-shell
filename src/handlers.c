#include "handlers.h"

/**
 * @fn sigchild_handler
 * @brief handles SIGCHLD signals. When such a signal is received, it wait() the sender and remove it's pid 
 *        from the list of current running processus.
 * @param sig signal identifier
 * @return void
*/
void sigchild_handler(int sig) {

    pid_t pid = wait(NULL);

    if (!remove_from_list(fg_list, pid)) 
         remove_from_list(bg_list, pid);

    return;
}

/**
 * @fn parent_sigint_handler
 * @brief handles SIGINT signals for the shell only. When such a signal is received, it prints an acknowledgment message
 *        and gives back the prompt.
 * @param sig signal identifier
 * @return void
*/
void parent_sigint_handler(int sig) {
    printf("killing all sub-process !\n");
    printf("PUM-TZIN > ");
    fflush(stdout);
    return;
}