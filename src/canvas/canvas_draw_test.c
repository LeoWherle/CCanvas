/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** Experimental canvas drawing
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>
#include "canvas.h"
#include "errorhandling.h"

static sfVector3f get_step_inc(const brush_t *brush, sfVector2i pos)
{
    sfVector3f step_inc = {.x = 0, .y = 0, .z = 0};
    int dx = (int)abs(pos.x - brush->old_pos.x);
    int dy = (int)abs(pos.y - brush->old_pos.y);
    int steps = (dx > dy) ? dx : dy;

    step_inc.z = steps;
    step_inc.x = (float)(pos.x - brush->old_pos.x) / (float)step_inc.z;
    step_inc.y = (float)(pos.y - brush->old_pos.y) / (float)step_inc.z;
    return step_inc;
}

void draw_smooth_line(UNUSED sfRenderWindow *window, sfVector2i pos,
brush_t *brush, canvas_t *canvas)
{
    sfVector3f step_inc = get_step_inc(brush, pos);
    float x = brush->old_pos.x;
    float y = brush->old_pos.y;

    if (brush->old_pos.x == -1 && brush->old_pos.y == -1) {
        brush->old_pos = pos;
        return;
    }
    for (int i = 0; i <= step_inc.z; i++) {
        if (brush->shape == SQUARE)
            draw_shape((sfVector2i){x, y}, canvas, brush, draw_square);
        if (brush->shape == CIRCLE)
            draw_shape((sfVector2i){x, y}, canvas, brush, draw_circle);
        x += step_inc.x;
        y += step_inc.y;
    }
    brush->old_pos = pos;
}
