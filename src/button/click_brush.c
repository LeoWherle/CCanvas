/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** functions for the buttons in the menu edit
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

void set_eraser(UNUSED button_t *button, UNUSED node_t *b_list, brush_t *brush,
UNUSED canvas_t *canva)
{
    brush->tool = ERASER;
}

void set_brush(UNUSED button_t *button, UNUSED node_t *b_list, brush_t *brush,
UNUSED canvas_t *canva)
{
    brush->tool = BRUSH;
}

void set_fill(UNUSED button_t *button, UNUSED node_t *b_list, brush_t *brush,
UNUSED canvas_t *canva)
{
    brush->tool = FILL;
}

void increase_size(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    if (brush->size < 100)
        brush->size += 5;
}

void decrease_size(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    if (brush->size > 5)
        brush->size -= 5;
}
