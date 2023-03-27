/*
** EPITECH PROJECT, 2022
** window_manager.c
** File description:
** window gestion for my_hunter
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include "chained_list.h"
#include "button.h"
#include "errorhandling.h"
#include "my_string.h"
#include "my_window.h"

static int detect_display(char *env[])
{
    int i = 0;

    if (env[0] == NULL)
        return (-1);
    while (env[i]) {
        if (my_strcmp(env[i], "DISPLAY") == 0) {
            return (0);
        }
        i++;
    }
    return (-1);
}

sfRenderWindow *create_window(char *env[])
{
    sfVideoMode v_mode = {1920, 1080, 32};
    static sfRenderWindow *window = NULL;
    int FPS = 60;
    int display = 0;

    if (window != NULL)
        return (window);
    display = detect_display(env);
    if (display == -1) {
        write(2, "No display detected :(\n", 23);
        return (NULL);
    }
    window = sfRenderWindow_create(v_mode, "MyPaint", sfResize | sfClose, NULL);
    ASSERT_MALLOC(window, NULL)
    sfRenderWindow_setFramerateLimit(window, FPS);
    return (window);
}

void destroy_bg(bg_t *bg)
{
    sfSprite_destroy(bg->sprite);
    sfTexture_destroy(bg->texture);
    free(bg);
}

bg_t *create_background(bg_t *bg, sfRenderWindow *window)
{
    bg = malloc(sizeof(bg_t));
    bg->texture = sfTexture_createFromFile("assets/background.png", NULL);
    ASSERT_MALLOC(bg->texture, NULL);
    bg->sprite = sfSprite_create();
    ASSERT_MALLOC(bg->sprite, NULL);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfSprite_setPosition(bg->sprite, (sfVector2f){1, 2});
    bg->window = window;
    return (bg);
}

void draw_side_menus(sfRenderWindow *window, button_t *button, brush_t *brush,
list_t *color_text)
{
    sfColor color = sfColor_fromInteger(brush->color);

    color = sfColor_fromRGBA(color.a, color.b, color.g, color.r);
    if (button->id == 14) {
        sfRectangleShape_setFillColor(button->rect, color);
        draw_text(window, color_text, brush);
    }
    if ((button->id == 26 && brush->shape == SQUARE) ||
    (button->id == 25 && brush->shape == CIRCLE))
        sfRectangleShape_setFillColor(button->rect, sfBlack);
    if ((button->id == 26 && brush->shape == CIRCLE) ||
    (button->id == 25 && brush->shape == SQUARE))
        sfRectangleShape_setFillColor(button->rect, sfWhite);
}
