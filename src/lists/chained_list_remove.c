/*
** EPITECH PROJECT, 2023
** graphical [WSL: fedora]
** File description:
** chained__list_remove
*/

#include <stdlib.h>
#include "chained_list.h"

/**
 * @brief removes the first node from the list and returns the data
 * destroys the node
 *
 * @param list the list to remove from
 * @return void* the data from the node
 */
void *pop_first_node(list_t *list)
{
    node_t *node = NULL;
    void *data = NULL;

    ASSERT_MALLOC(list->head, NULL)
    node = list->head;
    data = node->data;
    list->head = node->next;
    if (list->head == NULL)
        list->tail = NULL;
    list->size--;
    free(node);
    return data;
}

/**
 * @brief removes the last node from the list and returns the data
 * destroys the node
 *
 * @param list the list to remove from
 * @return void* the data from the node
 */
static void *pop_node_data(list_t *list, void *data)
{
    node_t *node = NULL;
    node_t *node_prev = NULL;

    node_prev = list->head;
    node = find_node(list, data);
    ASSERT_MALLOC(node, data)
    if (node == node_prev) {
        list->head = node->next;
        node_prev = NULL;
    } else {
        while (node_prev->next != node) {
            node_prev = node_prev->next;
        }
        node_prev->next = node->next;
    }
    if (node == list->tail)
        list->tail = node_prev;
    list->size--;
    free(node);
    return data;
}

static void *pop_last_node(list_t *list)
{
    node_t *node = NULL;
    node_t *temp = NULL;
    void *data = NULL;

    ASSERT_MALLOC(list->head, NULL)
    temp = list->head;
    node = list->tail;
    while (temp->next != node) {
        temp = temp->next;
    }
    temp->next = NULL;
    data = node->data;
    list->tail = temp;
    list->size--;
    free(node);
    return data;
}

/**
 * @brief removes the last node from the list and returns the data
 * destroys the node if data is NULL else removes the node containing the data
 *
 * @param list the list to remove from
 * @param data if not NULL, the data to remove
 * @return void* the data from the popped node NULL if not found or
 * if list is empty
 */
void *pop_node(list_t *list, void *data)
{
    ASSERT_MALLOC(list->head, NULL)
    if (data == NULL) {
        if (list->size == 1)
            data = pop_first_node(list);
        else
            data = pop_last_node(list);
    } else {
        data = pop_node_data(list, data);
    }
    return data;
}
