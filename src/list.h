#ifndef LIST_H
#define LIST_H

#include "csapp.h"

/*basic chained list structure, used to store pids of foreground and background process*/
struct cell {
    pid_t data;
    struct cell *next;
};
typedef struct cell cell_t;

struct list {
    cell_t *head;
};
typedef struct list *list_t;

/**
 * @brief creates a new cell which contains the given pid
 * @param pid pid of the process to be stored in the list
 * @return the created cell
*/
cell_t *create_cell(pid_t pid);

/**
 * @brief creates an empty list by allocating memory
 * @param void
 * @return the created list
*/
list_t create_list();

/**
 * @brief adds a given pid to the list
 * @param list list in which one wants to store the pid
 * @param pid pid of the process to be stored in the list
 * @return the list with a new cell, containing the pid.
*/
void add_to_list(list_t list, pid_t pid);

/**
 * @brief removes a given pid of the list. It returns an int indicating if the pid was in the list or not.
 * @param list list from which one wants to remove the pid
 * @param pid pid of the process to be removed from the list
 * @return 0 if the pid wasn't in the list, 1 otherwise
*/
int remove_from_list(list_t list, pid_t pid);

/**
 * @brief returns an int indicating if the given list is empty
 * @param list the list to be tested
 * @return 0 if it's empty, 1 otherwise
*/
int is_empty_list(list_t list);

#endif // LIST_H
