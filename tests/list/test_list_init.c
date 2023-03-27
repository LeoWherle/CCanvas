/*
** EPITECH PROJECT, 2023
** graphical [WSL: fedora]
** File description:
** test_list_init
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "chained_list.h"

Test(list_init, test_list_init)
{
    list_t *list = NULL;
    list = init_list();

    cr_assert_not_null(list);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
    cr_assert_eq(list->size, 0);
    cr_assert_not_null(list->intrf);
    cr_assert_not_null(list->intrf->append);
    cr_assert_not_null(list->intrf->insert);
    cr_assert_not_null(list->intrf->popf);
    cr_assert_not_null(list->intrf->pop);
    cr_assert_not_null(list->intrf->append_list);
    cr_assert_not_null(list->intrf->insert_list);
    cr_assert_not_null(list->intrf->print);
    cr_assert_not_null(list->intrf->find);
    cr_assert_not_null(list->intrf->destroy);
}

Test(node_init, test_node_init)
{
    node_t *node = NULL;
    node = init_node(NULL);

    cr_assert_not_null(node);
    cr_assert_null(node->data);
    cr_assert_null(node->next);
}

Test(list_init, test_list_one_interface)
{
    list_t *list = NULL;
    list_t *list2 = NULL;

    list = init_list();
    list2 = init_list();
    cr_assert_eq(list->intrf, list2->intrf);
}

Test(list_init, test_list_insert_empy_list)
{
    list_t *list = NULL;
    list = init_list();

    list->intrf->insert(list, "END");
    cr_assert_eq(list->size, 1);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_str_eq(list->head->data, "END");
    cr_assert_str_eq(list->tail->data, "END");
}

Test(list_init, test_list_insert_list)
{
    list_t *list = NULL;
    list = init_list();

    list->intrf->insert(list, "END");
    list->intrf->insert(list, "MIDDLE");
    list->intrf->insert(list, "START");
    cr_assert_eq(list->size, 3);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_str_eq(list->head->data, "START");
    cr_assert_str_eq(list->head->next->data, "MIDDLE");
    cr_assert_str_eq(list->head->next->next->data, "END");
    cr_assert_str_eq(list->tail->data, "END");
}

Test(list_init, test_list_append_empy_list)
{
    list_t *list = NULL;
    list = init_list();

    list->intrf->append(list, "START");
    cr_assert_eq(list->size, 1);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_str_eq(list->head->data, "START");
    cr_assert_str_eq(list->tail->data, "START");
}

Test(list_init, test_list_append_list)
{
    list_t *list = NULL;
    list = init_list();

    list->intrf->append(list, "START");
    list->intrf->append(list, "MIDDLE");
    list->intrf->append(list, "END");
    cr_assert_eq(list->size, 3);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_str_eq(list->head->data, "START");
    cr_assert_str_eq(list->head->next->data, "MIDDLE");
    cr_assert_str_eq(list->head->next->next->data, "END");
    cr_assert_str_eq(list->tail->data, "END");
}
