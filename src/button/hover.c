/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** hover manager for buttons
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "chained_list.h"
#include "button.h"
#include "errorhandling.h"

void shade_button_color(button_t *button, UNUSED node_t *b_list)
{
    sfColor color = sfColor_fromRGB(160, 160, 160);

    sfRectangleShape_setFillColor(button->rect, color);
}
