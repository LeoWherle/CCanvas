/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** test_list_exec
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "chained_list.h"

void ceasar_cipher(void *data)
{
    char *str = (char *)data;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + 3) % 26 + 'a';
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + 3) % 26 + 'A';
    }
}

Test(list_exec, test_list_exec)
{
    list_t *list = NULL;
    char *str = NULL;

    str = malloc(sizeof(char) * 5);
    strcpy(str, "test");
    list = init_list();
    list->intrf->append(list, str);
    node_exec(list, ceasar_cipher);
    cr_assert_str_eq(list->head->data, "whvw");
}

Test(list_exec, test_list_exec_multiple)
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
    node_exec(list, ceasar_cipher);
    cr_assert_str_eq(list->head->data, "whvw1");
    cr_assert_str_eq(list->head->next->data, "whvw2");
    cr_assert_str_eq(list->head->next->next->data, "whvw3");
}
