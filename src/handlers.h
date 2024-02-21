#ifndef HANDLERS_H
#define HANDLERS_H

#include "csapp.h"
#include "interpreter.h"
#include "list.h"
#include "error.h"
#include "global.h"

//char *PROMPT = "PUM-TZIN > ";

void sigchild_handler(int sig);

void parent_sigint_handler(int sig);

#endif // HANDLERS_H