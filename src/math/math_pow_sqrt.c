/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** math_pow_sqr
*/

#include "my_math.h"

int my_pow(int nb, int pow)
{
    int res = nb;

    if (pow == 0)
        return (1);
    for (int i = 1; i < pow; i++)
        res *= nb;
    return res;
}

int my_sqrt(int nb)
{
    int res = 0;
    int i = 0;

    for (i = 0; i < nb; i++) {
        if (my_pow(i, 2) == nb)
            return i;
        if (my_pow(i, 2) > nb)
            return res;
        res = i;
    }
    return res;
}
