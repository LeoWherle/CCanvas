/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas_display
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "canvas.h"

void display_canvas(sfRenderWindow *window, canvas_t *canvas)
{
    sfUint8 *pixels = (sfUint8 *)canvas->pixels;

    sfTexture_updateFromPixels(canvas->texture, pixels,
    canvas->width, canvas->height, 0, 0);
    sfSprite_setTexture(canvas->sprite, canvas->texture, sfFalse);
    sfRenderWindow_drawSprite(window, canvas->sprite, NULL);
}
