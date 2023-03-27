/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas_draw
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "canvas.h"
#include <math.h>
#include "errorhandling.h"
#include "colors.h"
#include "button.h"
#include "my_window.h"

void draw_square(UNUSED sfVector2i pos, sfVector2i pix,
canvas_t *cnvas, brush_t *brsh)
{
    sfUint32 color = brsh->color;

    if (brsh->tool == ERASER)
        color = Transparent;
    set_pixel(pix.x, pix.y, cnvas, color);
}

static int is_in_circle(int c_radius, sfVector2i c_center, int x, int y)
{
    if (pow(x - c_center.x, 2) + pow(y - c_center.y, 2) <= pow(c_radius, 2)) {
        return 1;
    }
    return 0;
}

void draw_circle(sfVector2i pos, sfVector2i pix, canvas_t *cnvas, brush_t *brsh)
{
    int circle_radius = brsh->size / 2;
    sfUint32 color = brsh->color;

    if (brsh->tool == ERASER)
        color = Transparent;
    if (is_in_circle(circle_radius, pos, pix.x, pix.y)) {
        set_pixel(pix.x, pix.y, cnvas, color);
    }
}

void draw_shape(sfVector2i pos, canvas_t *canvas, brush_t *brush, shape_ft fun)
{
    uint bot = get_bot(pos, brush->size, canvas);
    uint right = get_right(pos, brush->size, canvas);
    uint left = get_left(pos, brush->size, canvas);
    uint top = get_top(pos, brush->size, canvas);
    uint y = 0;
    uint x = 0;

    for (y = top; y < bot; y++) {
        for (x = left; x < right; x++) {
            fun(pos, (sfVector2i){x, y}, canvas, brush);
        }
    }
}

void draw(sfRenderWindow *window, canvas_t *canvas, brush_t *brush)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (!(pos.x >= canvas->pos.x && pos.y >= canvas->pos.y
    && pos.x <= canvas->pos.x + canvas->width &&
    pos.y <= canvas->pos.y + canvas->height))
        return;
    pos = (sfVector2i){pos.x - (int)canvas->pos.x, pos.y - (int)canvas->pos.y};
    if (brush->tool == FILL)
        fill_canvas_hex(canvas, brush->color);
    if (brush->tool == BRUSH || brush->tool == ERASER) {
        draw_smooth_line(window, pos, brush, canvas);
    }
    if (brush->tool == EYEDROPPER)
        brush->color = get_color(pos.x, pos.y, canvas);
}
