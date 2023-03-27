/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** click color red and green
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

void increase_blue(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.g < (255 - 4)) {
        color = sfColor_fromRGBA(color.r, color.g + 5, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, 255, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    }
}

void decrease_blue(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.g > (0 + 4)) {
        color = sfColor_fromRGBA(color.r, color.g - 5, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, 0, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    }
}

void increase_alpha(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.r < (255 - 4)) {
        color = sfColor_fromRGBA(color.r + 5, color.g, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(255, color.g, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    }
}

void decrease_alpha(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.r > (0 + 4)) {
        color = sfColor_fromRGBA(color.r - 5, color.g, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(0, color.g, color.b, color.a);
        brush->color = sfColor_toInteger(color);
    }
}
