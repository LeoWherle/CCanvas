/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** text color manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "button.h"
#include "my_window.h"
#include "my_string.h"

void destroy_text(void *data)
{
    text_t *text = data;

    sfText_destroy(text->str);
    sfFont_destroy(text->font);
    free(text);
}

void draw_text(sfRenderWindow *window, list_t *color_text, brush_t *brush)
{
    node_t *node = color_text->head;
    text_t *text = node->data;
    sfColor color_s = sfColor_fromInteger(brush->color);
    int color = 0;

    while (node->next != NULL) {
        text = node->data;
        if (text->color_type == 0)
            color = color_s.a;
        if (text->color_type == 1)
            color = color_s.b;
        if (text->color_type == 2)
            color = color_s.g;
        if (text->color_type == 3)
            color = color_s.r;
        if (text->type == 2)
            sfText_setString(text->str, nbr_to_str(color));
        sfRenderWindow_drawText(window, text->str, NULL);
        node = node->next;
    }
}

text_t *create_text(char *str, int size, sfVector2f pos, text_t *text)
{
    text = malloc(sizeof(text_t));
    static int color_type = -1;

    text->font = sfFont_createFromFile("assets/font.ttf");
    ASSERT_MALLOC(text->font, NULL);
    text->str = sfText_create();
    ASSERT_MALLOC(text->str, NULL);
    sfText_setFont(text->str, text->font);
    sfText_setString(text->str, str);
    sfText_setCharacterSize(text->str, size);
    sfText_setPosition(text->str, pos);
    if (str[0] == '0' || str[0] == '2')
        text->type = 2;
    else
        text->type = 1;
    color_type++;
    color_type = color_type % 4;
    text->color_type = color_type;
    return (text);
}

static text_t *create_color_values(list_t *color_text, text_t *text)
{
    color_text->intrf->append(color_text, text);
    text = create_text("Alpha", 25, (sfVector2f){1750, 770}, text);
    ASSERT_MALLOC(text, NULL);
    color_text->intrf->append(color_text, text);
    text = create_text("0", 25, (sfVector2f){1765, 510}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfRed);
    color_text->intrf->append(color_text, text);
    text = create_text("0", 25, (sfVector2f){1765, 610}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfGreen);
    color_text->intrf->append(color_text, text);
    text = create_text("0", 25, (sfVector2f){1765, 710}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfBlue);
    color_text->intrf->append(color_text, text);
    text = create_text("255", 25, (sfVector2f){1765, 810}, text);
    ASSERT_MALLOC(text, NULL);
    color_text->intrf->append(color_text, text);
    return (text);
}

list_t *create_color_text_list(list_t *color_text)
{
    text_t *text = NULL;

    color_text = init_list();
    ASSERT_MALLOC(color_text, NULL);
    text = create_text("Red", 25, (sfVector2f){1770, 475}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfRed);
    color_text->intrf->append(color_text, text);
    text = create_text("Green", 25, (sfVector2f){1750, 570}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfGreen);
    color_text->intrf->append(color_text, text);
    text = create_text("Blue", 25, (sfVector2f){1760, 670}, text);
    ASSERT_MALLOC(text, NULL);
    sfText_setColor(text->str, sfBlue);
    ASSERT_MALLOC(create_color_values(color_text, text), NULL);
    ASSERT_MALLOC(create_tool_text(color_text, text), NULL);
    return (color_text);
}
