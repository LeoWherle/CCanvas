/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** my_string functions
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcat(char *dest, char const *src);
    char *nbr_to_str(long long nb);

    struct my_string_s {
        int (*length)(char const *str);
        int (*compare)(char const *s1, char const *s2);
    };

#endif /* MY_STRING_H_ */
