/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** color menu creation
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "button.h"
#include "chained_list.h"
#include "errorhandling.h"

static button_t *create_color_menu_ba(list_t *temp, button_t *button)
{
    button = init_button((sfVector2f){1840, 700}, (sfVector2f){45, 45}, temp,
    "assets/icon/plus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &increase_blue;
    button = init_button((sfVector2f){1715, 700}, (sfVector2f){45, 45}, temp,
    "assets/icon/minus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &decrease_blue;
    button = init_button((sfVector2f){1840, 800}, (sfVector2f){45, 45}, temp,
    "assets/icon/plus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &increase_alpha;
    button = init_button((sfVector2f){1715, 800}, (sfVector2f){45, 45}, temp,
    "assets/icon/minus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &decrease_alpha;
    return (button);
}

button_t *create_color_menu_rg(list_t *temp, button_t *button)
{
    button = init_button((sfVector2f){1840, 500}, (sfVector2f){45, 45}, temp,
    "assets/icon/plus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &increase_red;
    button = init_button((sfVector2f){1715, 500}, (sfVector2f){45, 45}, temp,
    "assets/icon/minus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &decrease_red;
    button = init_button((sfVector2f){1840, 600}, (sfVector2f){45, 45}, temp,
    "assets/icon/plus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &increase_green;
    button = init_button((sfVector2f){1715, 600}, (sfVector2f){45, 45}, temp,
    "assets/icon/minus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &decrease_green;
    ASSERT_MALLOC(create_color_menu_ba(temp, button), NULL);
    return (button);
}
