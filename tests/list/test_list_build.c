/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** test_list_build
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "chained_list.h"

Test(list_build, test_list_build)
{
    list_t *list = NULL;
    char **array = NULL;

    list = init_list();
    list->intrf->append(list, "DATA");
    list->intrf->append(list, "DATA2");
    list->intrf->append(list, "DATA3");
    list->intrf->append(list, "DATA4");
    array = (char **)list_build(list);
    cr_assert_eq(list->size, 4);
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "DATA");
    cr_assert_str_eq(array[1], "DATA2");
    cr_assert_str_eq(array[2], "DATA3");
    cr_assert_str_eq(array[3], "DATA4");
    cr_assert_null(array[4]);
}

Test(list_build, test_list_build_empty)
{
    list_t *list = NULL;
    char **array = NULL;

    list = init_list();
    array = (char **)list_build(list);
    cr_assert_eq(list->size, 0);
    cr_assert_null(array);
}

Test(list_build, test_list_build_null)
{
    char **array = NULL;

    array = (char **)list_build(NULL);
    cr_assert_null(array);
}
