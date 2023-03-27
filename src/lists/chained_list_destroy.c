/*
** EPITECH PROJECT, 2023
** Personal_Clib [WSL: fedora]
** File description:
** chained_list_destroy
*/

#include <stdlib.h>
#include "chained_list.h"

/**
 * @brief Destroy the first node from the list
 *
 * @param list the list
 * @param free_data destructor for the data
 * @return int returns 0 if success, 1 if error or if list is empty
 */
int destroy_node(list_t *list, void (*free_data)(void *))
{
    node_t *node = NULL;
    node_t *tmp = NULL;

    ASSERT_MALLOC(list->head, 1)
    node = list->head;
    tmp = list->head->next;
    free_data(node->data);
    list->head = tmp;
    if (list->head == NULL)
        list->tail = NULL;
    list->size--;
    return 0;
}

/**
 * @brief Remove a node from the list
 *
 * @param list the list
 * @param data a void * to the data
 * @return int return 0 if success, 1 if node not found
 */
int delete_node(list_t *list, void *data, void (*free_data)(void *))
{
    node_t *node = NULL;
    node_t *node_prev = NULL;

    node_prev = list->head;
    node = find_node(list, data);
    ASSERT_MALLOC(node, 1)
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
    free_data(node->data);
    list->size--;
    return 0;
}

/**
 * @brief Destroy the list and it's components
 *
 * @param list the list
 * @param free_data destructor for the data
 */
void destroy_list(list_t *list, void (*free_data)(void *))
{
    node_t *node = NULL;
    node_t *tmp = NULL;

    node = list->head;
    while (node != NULL) {
        tmp = node->next;
        free_data(node->data);
        free(node);
        node = tmp;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);
}
