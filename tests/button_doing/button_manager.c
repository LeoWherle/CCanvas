/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** button manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "button.h"

void destroy_button(void *button)
{
    button_t *tmp = button;

    if (button == NULL)
        return;
    if (tmp->id > 0)
        sfTexture_destroy(tmp->texture);
    if (tmp->id == 1 || tmp->id == 2 || tmp->id == 4)
        destroy_list(tmp->sub_b, destroy_button);
    sfRectangleShape_destroy(tmp->rect);
    free(tmp);
}

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect button_hitbox;

    button_hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&button_hitbox, event->x, event->y)) {
        button->state = PRESSED;
        if (button->id > 0) {
            sfRectangleShape_setFillColor(button->rect, sfBlack);
        }
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool is_button_hovered(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect button_hitbox;

    button_hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    if (sfFloatRect_contains(&button_hitbox, event->x, event->y)) {
        button->state = HOVER;
        return (sfTrue);
    }
    return (sfFalse);
}

static void set_default_button_values(button_t *button, int id, sfVector2f pos)
{
    sfColor c_color = sfColor_fromRGB(90, 90, 90);

    if (id > 0)
        c_color = sfWhite;
    sfRectangleShape_setFillColor(button->rect, c_color);
    button->is_clicked = NULL;
    button->is_hover = NULL;
    button->state = NONE;
    button->id = id;
    button->sub_b = NULL;
    button->start = pos;
    button->open = sfFalse;
}

button_t *create_button_image(sfVector2f pos, sfVector2f size, list_t *blis,
char *img)
{
    button_t *button = malloc(sizeof(button_t));
    static int id = -2;

    id++;
    ASSERT_MALLOC(button, NULL);
    button->rect = sfRectangleShape_create();
    ASSERT_MALLOC(button->rect, NULL);
    if (img != NULL) {
        button->texture = sfTexture_createFromFile(img, NULL);
        ASSERT_MALLOC(button->texture, NULL);
        sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    }
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    set_default_button_values(button, id, pos);
    blis->intrf->append(blis, button);
    return (button);
}
