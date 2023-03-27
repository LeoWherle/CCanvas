/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** test_list_remove
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "chained_list.h"

Test(list_remove, test_list_remove_last_node)
{
    list_t *list = init_list();
    char *str = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");

    list->intrf->append(list, str);
    list->intrf->popf(list);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}

Test(list_remove, test_list_remove_first_node)
{
    list_t *list = init_list();
    char *str = NULL;
    char *str2 = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");

    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    list->intrf->popf(list);
    cr_assert_eq(list->head->data, str2);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 1);
}

Test(list_remove, test_list_remove_empty)
{
    list_t *list = init_list();

    list->intrf->popf(list);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}

Test(list_remove, test_list_remove_middle_node_pop)
{
    list_t *list = init_list();
    char *str = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    str3 = malloc(sizeof(char) * 6);
    strcpy(str3, "test3");
    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    list->intrf->append(list, str3);
    list->intrf->pop(list, str2);
    cr_assert_eq(list->head->data, str);
    cr_assert_eq(list->head->next->data, str3);
    cr_assert_eq(list->tail->data, str3);
    cr_assert_eq(list->size, 2);
}

Test(list_remove, test_list_remove_first_node_pop_data)
{
    list_t *list = init_list();
    char *str = NULL;
    char *str2 = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");

    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    list->intrf->pop(list, str);
    cr_assert_eq(list->head->data, str2);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 1);
}

Test(list_remove, test_list_remove_last_node_pop_data)
{
    list_t *list = init_list();
    char *str = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    str3 = malloc(sizeof(char) * 6);
    strcpy(str3, "test3");

    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    list->intrf->append(list, str3);
    list->intrf->pop(list, str3);
    cr_assert_eq(list->head->data, str);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 2);
}

Test(list_remove, test_list_remove_last_node_pop)
{
    list_t *list = init_list();
    char *str = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    str3 = malloc(sizeof(char) * 6);
    strcpy(str3, "test3");

    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    list->intrf->append(list, str3);
    list->intrf->pop(list, NULL);
    cr_assert_eq(list->head->data, str);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 2);
}

Test(list_remove, test_list_remove_empty_pop)
{
    list_t *list = init_list();

    list->intrf->pop(list, NULL);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}

Test(list_remove, test_list_remove_empty_pop2)
{
    list_t *list = init_list();
    char *str = NULL;
    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");
    node_t *node = init_node(str);

    list->intrf->pop(list, node);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}

Test(list_remove, test_list_remove_one_pop)
{
    list_t *list = init_list();
    char *str = NULL;
    str = malloc(sizeof(char) * 6);
    strcpy(str, "test1");

    list->intrf->append(list, str);
    list->intrf->pop(list, NULL);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}
