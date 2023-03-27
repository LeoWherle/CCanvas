/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdlib.h>
#include "chained_list.h"
#include "my_window.h"
#include "my_event.h"
#include "button.h"
#include "canvas.h"
#include "errorhandling.h"
#include "colors.h"
#include "my_string.h"

static void destroy_all(sfRenderWindow *window, list_t *b_list)
{
    destroy_list(b_list, &destroy_button);
    sfRenderWindow_destroy(window);
}

static void draw_buttons(sfRenderWindow *window, list_t *b_list, brush_t *brush,
list_t *color_text)
{
    node_t *node = b_list->head;
    button_t *button = node->data;
    text_t *text = color_text->tail->data;

    while (node != NULL) {
        button = node->data;
        draw_side_menus(window, button, brush, color_text);
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        if (button->id == -2 && sfRectangleShape_getSize(button->rect).x != 0)
            draw_tool_text(text->str, window, brush);
        if (button->id <= 0 && sfRectangleShape_getSize(button->rect).x != 0 &&
        button->sub_b != NULL)
            draw_buttons(window, button->sub_b, brush, color_text);
        node = node->next;
    }
}

static int keep_window(sfRenderWindow *window, list_t *b_list, brush_t *brush,
canvas_t *canvas)
{
    bg_t *bg = NULL;
    list_t *color_text = NULL;

    color_text = create_color_text_list(color_text);
    ASSERT_MALLOC(color_text, 84);
    bg = create_background(bg, window);
    ASSERT_MALLOC(bg, -1);
    while (sfRenderWindow_isOpen(bg->window)) {
        sfRenderWindow_clear(bg->window, sfBlack);
        sfRenderWindow_drawSprite(bg->window, bg->sprite, NULL);
        display_canvas(bg->window, canvas);
        if (brush->active == 1) draw(bg->window, canvas, brush);
        draw_buttons(bg->window, b_list, brush, color_text);
        analyse_event(bg, b_list, brush, canvas);
        display_help_menu(bg->window, brush);
        sfRenderWindow_display(bg->window);
    }
    destroy_bg(bg);
    destroy_list(color_text, &destroy_text);
    return (0);
}

static int init_game(sfRenderWindow *window)
{
    list_t *b_list = NULL;
    brush_t *brush = NULL;
    canvas_t *canvas = NULL;
    int return_value = 0;

    b_list = init_list();
    ASSERT_MALLOC(b_list, 84);
    ASSERT_MALLOC(create_buttons(b_list), -1);
    ASSERT_MALLOC(create_sub_buttons(b_list), -1);
    canvas = create_canvas(1660, 1000);
    ASSERT_MALLOC(canvas, 84);
    brush = create_brush();
    ASSERT_MALLOC(brush, 84);
    return_value = keep_window(window, b_list, brush, canvas);
    destroy_all(window, b_list);
    destroy_canvas(canvas);
    destroy_brush(brush);
    return (return_value);
}

int main(int ac, char *av[] UNUSED, char *env[])
{
    sfRenderWindow *window = NULL;
    int return_value = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write(1, "USAGE\n\t./my_paint\n\nDESCRIPTION\n\tMyPaint is a simple "
        "paint program, allowing you to draw, open or save an image.\n", 112);
        return (0);
    }
    if (ac != 1)
        return (84);
    window = create_window(env);
    if (window == NULL)
        return (84);
    return_value = init_game(window);
    if (return_value == -1) {
        write(2, "Don't touch the assets !\n", 25);
        return_value = 84;
    }
    return (return_value);
}
