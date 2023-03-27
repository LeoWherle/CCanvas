/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** test_list_data_destructor
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "chained_list.h"


// Doesn't make any sense this is not a valid test
Test(destructor, test_list_data_destructor)
{
    list_t *list = NULL;
    char *str = NULL;

    str = malloc(sizeof(char) * 5);
    str[0] = 't';
    str[1] = 'e';
    str[2] = 's';
    str[3] = 't';
    str[4] = '\0';
    list = init_list();
    list->intrf->append(list, str);
    free_string(list->head->data);
    list->head->data = NULL;
    cr_assert_eq(list->head->data, NULL);
}
