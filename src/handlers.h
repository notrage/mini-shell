#ifndef HANDLERS_H
#define HANDLERS_H

#include "csapp.h"
#include "interpreter.h"
#include "list.h"
#include "error.h"
#include "global.h"

/**
 * @brief handles SIGCHLD signals. When such a signal is received, it wait() the sender and remove it's pid 
 *        from the list of current running processus.
 * @param sig signal identifier
 * @return void
*/
void sigchild_handler(int sig);

/**
 * @brief handles SIGINT signals for the shell only. When such a signal is received, it prints an acknowledgment message
 *        and gives back the prompt.
 * @param sig signal identifier
 * @return void
*/
void parent_sigint_handler(int sig);

#endif // HANDLERS_H