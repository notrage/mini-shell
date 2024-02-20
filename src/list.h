#ifndef LIST_H
#define LIST_H

#include "csapp.h"

struct cell {
    pid_t data;
    struct cell *next;
};
typedef struct cell cell_t;

struct list {
    cell_t *head;
};
typedef struct list *list_t;

list_t create_list();

void add_to_list(list_t list, pid_t pid);

int remove_from_list(list_t list, pid_t pid);

int is_empty_list(list_t list);

void print_list(list_t list);

#endif // LIST_H
