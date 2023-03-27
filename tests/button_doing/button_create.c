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
    if (tmp->sub_b != NULL)
        destroy_list(tmp->sub_b, destroy_button);
    sfRectangleShape_destroy(tmp->rect);
    free(tmp);
}

static void set_default_button_values(button_t *button, int id, sfVector2f pos)
{
    sfColor c_color = sfColor_fromRGB(90, 90, 90);

    if (id > 0)
        c_color = sfWhite;
    button->id = id;
    sfRectangleShape_setFillColor(button->rect, c_color);
    button->rect = NULL;
    button->is_clicked = NULL;
    button->is_hover = NULL;
    button->state = NONE;
    button->sub_b = NULL;
    button->pos = pos;
    button->open = sfFalse;
    button->image = NULL;
    button->text = NULL;
}

button_t *create_button_image2(sfVector2f pos, sfVector2f size, list_t *b_list,
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
    // button = button_add_image(button, img, size,(sfVector2f){0, 0});
    // ASSERT_MALLOC(button, NULL);
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    set_default_button_values(button, id, pos);
    b_list->intrf->append(b_list, button);
    return (button);
}

static void button_init_struct(button_t *button)
{
    button->id = 0;
    button->state = NONE;
    button->open = sfFalse;
    button->pos = (sfVector2f){0, 0};
    button->rect = NULL;
    button->texture = NULL;
    button->image = NULL;
    button->text = NULL;
    button->sub_b = NULL;
    button->is_clicked = NULL;
    button->is_hover = NULL;
}

static int button_init_components(button_t *button, sfVector2f pos,
sfVector2f size, int id)
{
    button->id = id;
    button->rect = sfRectangleShape_create();
    ASSERT_MALLOC(button->rect, 1);
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(90, 90, 90));
    return (0);
}

button_t *create_button(sfVector2f pos, sfVector2f size, list_t *b_list)
{
    button_t *button = NULL;
    int id = -2;

    id++;
    button = malloc(sizeof(button_t));
    ASSERT_MALLOC(button, NULL);
    button_init_struct(button);
    if (button_init_components(button, pos, size, id) == 1)
        return (NULL);
    b_list->intrf->append(b_list, button);
    return (button);
}

button_t *create_button_image(sfVector2f pos, sfVector2f size, list_t *b_list,
char *img)
{
    button_t *button = NULL;

    button = create_button(pos, size, b_list);
    if (img != NULL)
        button = button_add_image(button, img, pos, size);
    ASSERT_MALLOC(button, NULL);
    b_list->intrf->append(b_list, button);
    return (button);
}
