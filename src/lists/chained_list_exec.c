/*
** EPITECH PROJECT, 2023
** graphical [WSL: fedora]
** File description:
** chained_list_exec
*/

#include <stdlib.h>
#include "chained_list.h"

/**
 * @brief execute a function on all the data of a list
 *
 * @param list the list to execute on
 * @param exec_data the function to execute
 */
void node_exec(list_t *list, void (*exec_data)(void *))
{
    node_t *node = NULL;

    node = list->head;
    while (node != NULL) {
        exec_data(node->data);
        node = node->next;
    }
}
