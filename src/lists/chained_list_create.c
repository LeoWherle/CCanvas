/*
** EPITECH PROJECT, 2023
** Personal_Clib [WSL: fedora]
** File description:
** chained_list_create
*/

#include <stdlib.h>
#include "chained_list.h"

static list_interface_t *init_interface(void)
{
    list_interface_t *interface = NULL;

    interface = malloc(sizeof(list_interface_t));
    ASSERT_MALLOC(interface, NULL)
    interface->append = append_node;
    interface->insert = insert_node;
    interface->popf = pop_first_node;
    interface->pop = pop_node;
    interface->append_list = append_list;
    interface->insert_list = insert_list;
    interface->print = print_list;
    interface->find = find_node;
    interface->destroy = destroy_list;
    return interface;
}

/**
 * @brief Create a list
 *
 * @return list_t* return a pointer to the list
 */
list_t *init_list(void)
{
    static list_interface_t *interface = NULL;
    list_t *list = NULL;

    list = malloc(sizeof(list_t));
    ASSERT_MALLOC(list, NULL)
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    if (interface == NULL) {
        list->intrf = init_interface();
        ASSERT_MALLOC(list->intrf, NULL)
        interface = list->intrf;
    } else {
        list->intrf = interface;
    }
    return (list);
}

node_t *init_node(void *data)
{
    node_t *node = NULL;

    node = malloc(sizeof(node_t));
    ASSERT_MALLOC(node, NULL)
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * @brief Add a node at the end of the list
 *
 * @param list the list
 * @param data a void * to the data
 * @return int return 0 if success, 1 if error
 */
int append_node(list_t *list, void *data)
{
    node_t *node = NULL;

    node = init_node(data);
    ASSERT_MALLOC(node, 1)
    if (!list->head) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return 0;
}

/**
 * @brief Add a node at the beginning of the list
 *
 * @param list the list
 * @param data a void * to the data
 * @return int return 0 if success, 1 if error
 */
int insert_node(list_t *list, void *data)
{
    node_t *node = NULL;

    node = init_node(data);
    ASSERT_MALLOC(node, 1)
    if (!list->head) {
        list->tail = node;
    } else {
        node->next = list->head;
    }
    list->head = node;
    list->size++;
    return 0;
}
