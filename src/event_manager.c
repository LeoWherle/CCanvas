/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** event manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "button.h"
#include "chained_list.h"
#include "errorhandling.h"
#include "canvas.h"
#include "my_window.h"

node_t *find_id(node_t *list, int id)
{
    node_t *tmp = list;
    button_t *button = NULL;

    while (tmp != NULL) {
        button = tmp->data;
        if (button->id == id)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

static void analyse_mouse_click(list_t *b_list, sfEvent ev, brush_t *brush,
canvas_t *canva)
{
    node_t *node = b_list->head;
    button_t *btn = NULL;

    while (node != NULL) {
        btn = node->data;
        if (is_button_clicked(btn, &ev.mouseButton) && btn->is_clicked != NULL)
            btn->is_clicked(btn, b_list->head, brush, canva);
        if (btn->id <= 0 && sfRectangleShape_getSize(btn->rect).x != 0 &&
        btn->sub_b != NULL)
            analyse_mouse_click(btn->sub_b, ev, brush, canva);
        node = node->next;
    }
}

static void analyse_mouse_hover(list_t *b_list, sfEvent ev, brush_t *brush,
canvas_t *canva)
{
    node_t *node = b_list->head;
    button_t *btn = NULL;

    while (node != NULL) {
        btn = node->data;
        if (is_button_hovered(btn, &ev.mouseMove) && btn->id > 0
        && btn->open == sfFalse)
            shade_button_color(btn, b_list->head);
        if (is_button_hovered(btn, &ev.mouseMove) == sfFalse && btn->id > 0
        && btn->open == sfFalse)
            sfRectangleShape_setFillColor(btn->rect, sfWhite);
        if (btn->id <= 0 && sfRectangleShape_getSize(btn->rect).x != 0 &&
        btn->sub_b != NULL)
            analyse_mouse_hover(btn->sub_b, ev, brush, canva);
        node = node->next;
    }
}

static void init_click_tester(list_t *b_list, sfEvent ev, brush_t *brush,
canvas_t *canva)
{
    node_t *tmp = b_list->head;
    button_t *button = find_id(tmp, 0)->data;

    if (is_button_clicked(button, &ev.mouseButton))
        brush->active = 0;
    tmp = find_id(tmp, 1);
    if (close_menu(button, &ev.mouseButton) == sfTrue) {
        brush->help = 0;
        brush->help_menu = 0;
        while (tmp != NULL && button->id != 3) {
            button = tmp->data;
            button->open = sfFalse;
            sfRectangleShape_setFillColor(button->rect, sfWhite);
            tmp = tmp->next;
        }
        return;
    }
    analyse_mouse_click(b_list, ev, brush, canva);
}

void analyse_event(bg_t *bg, list_t *b_list, brush_t *brush,
canvas_t *canva)
{
    sfEvent event;
    sfRenderWindow *window = bg->window;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseMoved)
            analyse_mouse_hover(b_list, event, brush, canva);
        if (event.type == sfEvtMouseButtonPressed) {
            brush->active = 1;
            init_click_tester(b_list, event, brush, canva);
        }
        if (event.type == sfEvtMouseButtonReleased) {
            brush->active = 0;
            brush->old_pos = (sfVector2i){-1, -1};
        }
        if (event.type == sfEvtResized)
            resize_elements(bg, b_list, brush, canva);
    }
    draw_cursor(bg->window, brush, canva);
}
