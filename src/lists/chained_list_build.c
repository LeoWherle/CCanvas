/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** chained_list_build
*/

#include <stdlib.h>
#include "chained_list.h"

void **list_build(list_t *list)
{
    void **array = NULL;
    node_t *node = NULL;
    int i = 0;

    if (list == NULL || list->size == 0)
        return NULL;
    array = malloc(sizeof(void *) * (list->size + 1));
    ASSERT_MALLOC(array, NULL)
    node = list->head;
    while (node != NULL) {
        array[i] = node->data;
        node = node->next;
        i++;
    }
    array[i] = NULL;
    return array;
}
