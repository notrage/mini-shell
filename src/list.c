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
    cell_t *cell = create_cell(pid);
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
    cell_t *cell_to_remove = NULL;
    if (cell_to_iter == NULL) {
        return 0;
    }
    if (cell_to_iter->data == pid) {
        list->head = cell_to_iter->next;
        free(cell_to_iter);
        return 1;
    }
    while (cell_to_iter->next != NULL) {
        if (cell_to_iter->next->data == pid) {
            cell_to_remove = cell_to_iter->next;
            cell_to_iter->next = cell_to_iter->next->next;
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
