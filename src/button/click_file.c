/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** functions for file buttons
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdlib.h>
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"
#include "my_window.h"

void reset_canva(UNUSED button_t *button, UNUSED node_t *b_list, UNUSED
brush_t *brush, canvas_t *canva)
{
    canva->height = 1000;
    canva->width = 1660;
    if (canva->pixels != NULL) {
        canva->pixels = NULL;
        canva->pixels = malloc(sizeof(pixel_t) * canva->height * canva->width);
        if (canva->pixels == NULL)
            return;
    }
    fill_canvas_hex(canva, Transparent);
}

void set_circle_shape(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    brush->shape = CIRCLE;
}

void set_square_shape(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    brush->shape = SQUARE;
}
