/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** my_math
*/

#ifndef MY_MATH_H_
    #define MY_MATH_H_
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MIN(x, y) ((x) < (y) ? (x) : (y))
    #define MAX(x, y) ((x) > (y) ? (x) : (y))
    #define PI_ 3.14159265358979323846

    int my_pow(int nb, int power);
    int my_sqrt(int nb);

    typedef struct math_module_s {
        int (*pow)(int nb, int power);
        int (*sqrt)(int nb);
    } math_module_t;

#endif /* !MY_MATH_H_ */
