/*
** EPITECH PROJECT, 2023
** graphical [WSL: fedora]
** File description:
** chained_list_concat
*/

#include <stdlib.h>
#include "chained_list.h"

/**
 * @brief add list_src to the end of list_dest
 *
 * @param list_dest the list to add to
 * @param list_src the list to add
 */
void append_list(list_t *list_dest, list_t *list_src)
{
    node_t *node = NULL;

    ASSERT_MALLOC(list_dest,)
    ASSERT_MALLOC(list_src,)
    if (list_src->head == NULL) {
        return;
    }
    if (list_dest->head == NULL) {
        list_dest->head = list_src->head;
        list_dest->tail = list_src->tail;
    } else {
        node = list_dest->tail;
        node->next = list_src->head;
        list_dest->tail = list_src->tail;
    }
    list_src->head = NULL;
    list_src->tail = NULL;
    list_dest->size += list_src->size;
    list_src->size = 0;
}

/**
 * @brief add list_src to the start of list_dest
 *
 * @param list_dest the list to add to
 * @param list_src the list to add
 */
void insert_list(list_t *list_dest, list_t *list_src)
{
    node_t *node = NULL;

    ASSERT_MALLOC(list_dest,)
    ASSERT_MALLOC(list_src,)
    if (list_src->head == NULL) {
        return;
    }
    if (list_dest->head == NULL) {
        list_dest->tail = list_src->tail;
    } else {
        node = list_dest->head;
        list_src->tail->next = node;
    }
    list_dest->head = list_src->head;
    list_src->head = NULL;
    list_src->tail = NULL;
    list_dest->size += list_src->size;
    list_src->size = 0;
}
