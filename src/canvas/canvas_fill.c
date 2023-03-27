/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas_clear
*/

#include <SFML/Graphics.h>
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

/**
 * @brief Clear the canvas with a sfColor
 *
 * @param canvas the canvas to fill
 * @param color the color to fill the canvas with
 */
void fill_canvas(canvas_t *canvas, UNUSED sfColor color)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < canvas->width; i++) {
        for (j = 0; j < canvas->height; j++) {
            set_pixel_color(canvas->pixels[i + j * canvas->width], White);
        }
    }
}

/**
 * @brief Clear the canvas with a hex color
 *
 * @param canvas the canvas to fill
 * @param color must be a hex color e.g. 0xFF0000FF for red
 */
void fill_canvas_hex(canvas_t *canvas, sfUint32 color)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < canvas->width; i++) {
        for (j = 0; j < canvas->height; j++) {
            canvas->pixels[i + j * canvas->width].rgba = color;
        }
    }
}
