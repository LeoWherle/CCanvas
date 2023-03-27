/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** click_brush_tool
*/

#include <SFML/Graphics.h>
#include "canvas.h"
#include "canvas.h"
#include "button.h"
#include "errorhandling.h"

sfUint32 get_color(const uint x, const uint y, const canvas_t *canvas)
{
    sfUint32 color = 0;
    color = canvas->pixels[x + y * canvas->width].rgba;
    return color;
}

void set_picker(UNUSED button_t *button, UNUSED node_t *b_list, brush_t *brush,
UNUSED canvas_t *canva)
{
    brush->tool = EYEDROPPER;
}
