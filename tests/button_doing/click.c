/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** click manager for buttons
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

void open_button_menu(button_t *button, node_t *b_list, UNUSED brush_t *brush,
UNUSED canvas_t *canva)
{
    sfVector2f pos = (sfVector2f){0, 0};
    sfVector2f size = (sfVector2f){0, 0};
    button_t *tmp = NULL;

    tmp = find_id(b_list, 0);
    if (tmp == NULL)
        return;
    pos = sfRectangleShape_getPosition(button->rect);
    pos.y += 40;
    sfRectangleShape_setPosition(tmp->rect, pos);
    tmp->sub_b = button->sub_b;
    if (sfRectangleShape_getSize(tmp->rect).x == 0)
        size = (sfVector2f){100, 400};
    sfRectangleShape_setSize(tmp->rect, size);
    button->open = sfTrue;
}

void open_color_menu(button_t *button, node_t *b_list, UNUSED
brush_t *brush, UNUSED canvas_t *canva)
{
    sfVector2f pos = (sfVector2f){1700, 450};
    sfVector2f size = (sfVector2f){0, 0};
    button_t *tmp = NULL;

    tmp = find_id(b_list, -1);
    if (tmp == NULL)
        return;
    tmp->sub_b = button->sub_b;
    sfRectangleShape_setPosition(tmp->rect, pos);
    if (sfRectangleShape_getSize(tmp->rect).x == 0) {
        size = (sfVector2f){200, 600};
        button->open = sfTrue;
    } else {
        button->open = sfFalse;
        sfRectangleShape_setFillColor(button->rect, sfBlack);
    }
    sfRectangleShape_setSize(tmp->rect, size);
}

void reset_canva(UNUSED button_t *button, UNUSED node_t *b_list, UNUSED
brush_t *brush, canvas_t *canva)
{
    fill_canvas_hex(canva, White);
}

sfBool close_menu(button_t *button, sfMouseButtonEvent *ev)
{
    float size = sfRectangleShape_getSize(button->rect).x;

    if (is_button_clicked(button, ev) == sfFalse && size != 0) {
        sfRectangleShape_setSize(button->rect, (sfVector2f){0, 0});
        return (sfTrue);
    }
    return (sfFalse);
}
