/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** test_list_destroy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "chained_list.h"

Test(list_destroy, test_list_destroy_node)
{
    list_t *list = NULL;
    char *str = NULL;

    str = malloc(sizeof(char) * 5);
    strcpy(str, "test");
    list = init_list();
    list->intrf->append(list, str);
    destroy_node(list, &free_string);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
    cr_assert_eq(list->size, 0);
}

Test(list_destroy, test_list_delete_node)
{
    list_t *list = NULL;
    char *str = NULL;

    str = malloc(sizeof(char) * 5);
    strcpy(str, "test");
    list = init_list();
    list->intrf->append(list, str);
    cr_expect_eq(list->head->data, str);
    cr_expect_eq(list->tail->data, str);
    delete_node(list, str, &free_string);
    cr_assert_eq(list->size, 0);
    cr_assert_eq(list->head, NULL);
    cr_assert_eq(list->tail, NULL);
}

Test(list_destroy, test_list_delete_node_muliple)
{
    list_t *list = NULL;
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str1 = malloc(sizeof(char) * 6);
    strcpy(str1, "test1");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    str3 = malloc(sizeof(char) * 6);
    strcpy(str3, "test3");
    list = init_list();
    list->intrf->append(list, str1);
    list->intrf->append(list, str2);
    list->intrf->append(list, str3);
    delete_node(list, str3, &free_string);
    cr_assert_eq(list->head->data, str1);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 2);
}

Test(list_destroy, test_list_delete_node_muliple2)
{
    list_t *list = NULL;
    char *str = NULL;
    char *str2 = NULL;

    str = malloc(sizeof(char) * 5);
    strcpy(str, "test");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    list = init_list();
    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    delete_node(list, str, &free_string);
    cr_assert_eq(list->head->data, str2);
    cr_assert_eq(list->tail->data, str2);
    cr_assert_eq(list->size, 1);
}

// Can't test this function assert_free missing
Test(list_destroy, test_list_destroy_list)
{
    list_t *list = NULL;
    char *str = NULL;
    char *str2 = NULL;

    str = malloc(sizeof(char) * 5);
    strcpy(str, "test");
    str2 = malloc(sizeof(char) * 6);
    strcpy(str2, "test2");
    list = init_list();
    list->intrf->append(list, str);
    list->intrf->append(list, str2);
    destroy_list(list, &free_string);
}
