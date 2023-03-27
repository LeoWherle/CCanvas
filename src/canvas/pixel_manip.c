/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** pixel_manip
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

pixel_t *get_pixel(uint x, uint y, canvas_t *canvas)
{
    return (&canvas->pixels[x + y * canvas->width]);
}

sfUint8 get_color_shade(const uint x, const uint y, const canvas_t *canvas)
{
    return canvas->pixels[x + y * canvas->width].a;
}

sfUint32 color_from_argb(sfUint8 a, sfUint8 r, sfUint8 g, sfUint8 b)
{
    sfUint32 color = 0;
    color = (color >> 24) | a;
    color = (color >> 16) | b;
    color = (color >> 8) | g;
    color = (color >> 0) | r;
    return color;
}

pixel_t blend_color(pixel_t brush, pixel_t canva)
{
    pixel_t result;

    result.r = (sfUint8)((brush.r + canva.r) / 2);
    result.g = (sfUint8)((brush.g + canva.g) / 2);
    result.b = (sfUint8)((brush.b + canva.b) / 2);
    result.a = (sfUint8)(255);
    return result;
}

void set_pixel(uint x, uint y, canvas_t *canvas, sfUint32 color)
{
    pixel_t color_blend UNUSED;
    pixel_t old_color;
    pixel_t new_color;

    old_color = canvas->pixels[x + y * canvas->width];
    new_color.rgba = color;
    color_blend = blend_color(old_color, new_color);
    canvas->pixels[x + y * canvas->width] = new_color;
}
