/*
** EPITECH PROJECT, 2023
** graphical [WSL: fedora]
** File description:
** chained_list_utils
*/

#include <stdlib.h>
#include "chained_list.h"

/**
 * @brief find a node in a list
 *
 * @param list the list to search in
 * @param data the data to search for
 * @return node_t* the node containing the data
 */
node_t *find_node(list_t *list, void const *const data)
{
    node_t *node = NULL;

    node = list->head;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
