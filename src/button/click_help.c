/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** click help
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"


brush_t *create_infos(brush_t *brush)
{
    brush->font = sfFont_createFromFile("assets/font.ttf");
    ASSERT_MALLOC(brush->font, NULL);
    brush->help_text = sfText_create();
    ASSERT_MALLOC(brush->help_text, NULL);
    sfText_setFont(brush->help_text, brush->font);
    sfText_setString(brush->help_text, "Made by theodore.magna and leo.wehrle");
    sfText_setColor(brush->help_text, sfRed);
    sfText_setPosition(brush->help_text, (sfVector2f){500, 10});
    brush->help_texture = sfTexture_createFromFile("assets/helpmenu.png", NULL);
    ASSERT_MALLOC(brush->help_texture, NULL);
    brush->help_sprite = sfSprite_create();
    ASSERT_MALLOC(brush->help_sprite, NULL);
    sfSprite_setTexture(brush->help_sprite, brush->help_texture, sfTrue);
    sfSprite_setPosition(brush->help_sprite, (sfVector2f){200, 200});
    return (brush);
}

void display_help_menu(sfRenderWindow *window, brush_t *brush)
{
    if (brush->help == 1)
        sfRenderWindow_drawText(window, brush->help_text, NULL);
    if (brush->help_menu == 1)
        sfRenderWindow_drawSprite(window, brush->help_sprite, NULL);
}

void display_info(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    if (brush->help == 1)
        brush->help = 0;
    else
        brush->help = 1;
}

void undo(UNUSED button_t *button, UNUSED node_t *b_list,
UNUSED brush_t *brush, canvas_t *canva)
{
    sfUint32 *pixels = NULL;

    canva->height = 1000;
    canva->width = 1660;
    if (canva->pixels != NULL) {
        canva->pixels = NULL;
        canva->pixels = malloc(sizeof(pixel_t) * canva->height * canva->width);
        if (canva->pixels == NULL)
            return;
    }
    pixels = (sfUint32 *)canva->pixels;
    create_color_spectrum(pixels, canva->width, canva->height, 255);
}

void display_help(UNUSED button_t *button, UNUSED node_t *b_list,
brush_t *brush, UNUSED canvas_t *canva)
{
    if (brush->help_menu == 1)
        brush->help_menu = 0;
    else
        brush->help_menu = 1;
}
