/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** get_corners
*/

#include <SFML/Graphics.h>
#include "canvas.h"

int get_top(sfVector2i pos, uint size, canvas_t *canvas)
{
    int value = (pos.y - (int)(size / 2));

    if (value < 0)
        return 0;
    if (value > canvas->height)
        return canvas->height;
    return value;
}

int get_bot(sfVector2i pos, uint size, canvas_t *canvas)
{
    int value = (pos.y + (int)(size / 2));

    if (value < 0)
        return 0;
    if (value > canvas->height)
        return canvas->height;
    return value;
}

int get_left(sfVector2i pos, uint size, canvas_t *canvas)
{
    int value = (pos.x - (int)(size / 2));

    if (value < 0)
        return 0;
    if (value > canvas->width)
        return canvas->width;
    return value;
}

int get_right(sfVector2i pos, uint size, canvas_t *canvas)
{
    int value = (pos.x + (int)(size / 2));

    if (value < 0)
        return 0;
    if (value > canvas->width)
        return canvas->width;
    return value;
}
