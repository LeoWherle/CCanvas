/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** Resize
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include "chained_list.h"
#include "button.h"
#include "errorhandling.h"
#include "my_string.h"
#include "my_window.h"

static void resize_canva(sfVector2f scale, UNUSED sfVector2f pos,
canvas_t *canva)
{
    canva->pos.x = 20 * scale.x;
    canva->pos.y = 50 * scale.y;
    sfSprite_setPosition(canva->sprite, canva->pos);
}

static sfVector2f get_scale(sfVector2f scale, sfVector2u win_size)
{
    scale.y = win_size.y;
    scale.x = win_size.x;
    scale.y /= 1080;
    scale.x /= 1920;
    scale.y = 1 / scale.y;
    scale.x = 1 / scale.x;
    return (scale);
}

static void close_all_menu(button_t *button, sfVector2f scale, sfVector2f pos)
{
    if (button->id <= 0)
        sfRectangleShape_setSize(button->rect, (sfVector2f){0, 0});
    else
        button->open = sfFalse;
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setScale(button->rect, scale);
}

void resize_elements(bg_t *bg, list_t *b_list, UNUSED brush_t *brush,
canvas_t *canva)
{
    sfVector2u win_size = sfRenderWindow_getSize(bg->window);
    node_t *node = b_list->head;
    button_t *button = node->data;
    sfVector2f scale;
    sfVector2f pos;

    scale = get_scale(scale, win_size);
    while (node != NULL) {
        button = node->data;
        pos = button->start;
        pos.x *= scale.x;
        pos.y *= scale.y;
        close_all_menu(button, scale, pos);
        if (button->id <= 0 && sfRectangleShape_getSize(button->rect).x != 0 &&
        button->sub_b != NULL)
            resize_elements(bg, button->sub_b, brush, canva);
        node = node->next;
    }
    resize_canva(scale, pos, canva);
}
