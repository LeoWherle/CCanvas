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

void increase_red(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.a < (255 - 4)) {
        color = sfColor_fromRGBA(color.r, color.g, color.b, color.a + 5);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, color.g, color.b, 255);
        brush->color = sfColor_toInteger(color);
    }
}

void decrease_red(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.a > (0 + 4)) {
        color = sfColor_fromRGBA(color.r, color.g, color.b, color.a - 5);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, color.g, color.b, 0);
        brush->color = sfColor_toInteger(color);
    }
}

void increase_green(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.b < (255 - 4)) {
        color = sfColor_fromRGBA(color.r, color.g, color.b + 5, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, color.g, 255, color.a);
        brush->color = sfColor_toInteger(color);
    }
}

void decrease_green(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    sfColor color = sfColor_fromInteger(brush->color);
    if (color.b > (0 + 4)) {
        color = sfColor_fromRGBA(color.r, color.g, color.b - 5, color.a);
        brush->color = sfColor_toInteger(color);
    } else {
        color = sfColor_fromRGBA(color.r, color.g, 0, color.a);
        brush->color = sfColor_toInteger(color);
    }
}
