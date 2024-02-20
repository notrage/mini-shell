#include "list.h"

list_t fg_list = NULL;
list_t bg_list = NULL;

cell_t *create_cell(pid_t pid) {
    cell_t *cell = malloc(sizeof(cell_t));
    cell->data = pid;
    cell->next = NULL;
    return cell;
}

list_t create_list() {
    list_t list = (list_t) malloc(sizeof(cell_t));
    list->head = NULL;
    return list;
}

void add_to_list(list_t list, pid_t pid) {
    cell_t *cell = malloc(sizeof(cell_t));
    cell -> data = pid;
    if (cell == NULL) exit(EXIT_FAILURE);
    cell_t *cell_to_iter = list -> head;
    if (cell_to_iter == NULL) {
        list->head = cell;
    return;
    }
    while (cell_to_iter->next != NULL) {
        cell_to_iter = cell_to_iter->next;
    }
    cell->next = NULL;
    cell_to_iter->next = cell;
    return;
}


int remove_from_list(list_t list, pid_t pid) {
    cell_t *cell_to_iter = list->head;
    if (is_empty_list(list)) return 0;
    while (cell_to_iter->next != NULL) {
        if (cell_to_iter->next->data == pid) {
            cell_t *cell_to_remove = cell_to_iter->next;
            cell_to_iter->next = cell_to_remove->next;
            free(cell_to_remove);
            return 1;
        }
        cell_to_iter = cell_to_iter->next;
    }
    return 0;
}

int is_empty_list(list_t list) {
    return list->head == NULL;
}

void print_list(list_t list) {
    cell_t *cell_to_iter = list->head;
    while (cell_to_iter != NULL) {
        fprintf(stderr, "%d\n", cell_to_iter->data);
        cell_to_iter = cell_to_iter->next;
    }
}