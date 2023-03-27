/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** new cursor
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "canvas.h"
#include "errorhandling.h"

sfCircleShape *create_cursor(brush_t *brush)
{
    brush->circle = sfCircleShape_create();
    brush->rect = sfRectangleShape_create();

    ASSERT_MALLOC(brush->circle, NULL);
    ASSERT_MALLOC(brush->rect, NULL);
    sfCircleShape_setRadius(brush->circle, brush->size / 2);
    sfCircleShape_setFillColor(brush->circle, sfTransparent);
    sfCircleShape_setOutlineColor(brush->circle, sfWhite);
    sfCircleShape_setOutlineThickness(brush->circle, 1);
    sfRectangleShape_setSize(brush->rect,
    (sfVector2f){brush->size, brush->size});
    sfRectangleShape_setFillColor(brush->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(brush->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(brush->rect, 1);
    return (brush->circle);
}

static void draw_rect_cursor(brush_t *brush, sfRenderWindow *window,
sfVector2i pos)
{
    sfRectangleShape_setSize(brush->rect,
    (sfVector2f){brush->size, brush->size});
    sfRectangleShape_setPosition(brush->rect, (sfVector2f){pos.x -
    brush->size / 2, pos.y - brush->size / 2});
    sfRenderWindow_drawRectangleShape(window, brush->rect, NULL);
}

static void draw_circle_cursor(brush_t *brush, sfRenderWindow *window,
sfVector2i pos)
{
    sfCircleShape_setRadius(brush->circle, brush->size / 2);
    sfCircleShape_setPosition(brush->circle, (sfVector2f){pos.x -
    brush->size / 2, pos.y - brush->size / 2});
    sfRenderWindow_drawCircleShape(window, brush->circle, NULL);
}

void draw_cursor(sfRenderWindow *window, brush_t *brush, canvas_t *canva)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (!(pos.x >= canva->pos.x && pos.y >= canva->pos.y
    && pos.x <= canva->pos.x + canva->width &&
    pos.y <= canva->pos.y + canva->height) || brush->tool == FILL ||
    brush->tool == SELECT || brush->tool == EYEDROPPER) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        return;
    }
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    if (brush->shape == CIRCLE) {
        draw_circle_cursor(brush, window, pos);
    } else {
        draw_rect_cursor(brush, window, pos);
    }
}
