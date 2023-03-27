/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** Reproduce the behavior of the strcmp function.
*/
#include "my_string.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    while ((i < len1 && i < len2) && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] == '=')
        return (0);
    return (s1[i] - s2[i]);
}
