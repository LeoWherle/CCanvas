/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** button creation
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "button.h"
#include "chained_list.h"
#include "errorhandling.h"

static button_t *create_menu_buttons(list_t *blis, button_t *button)
{
    button = init_button((sfVector2f){10, 10}, (sfVector2f){30, 35}, blis,
    "assets/icon/file.png");
    button->is_clicked = &open_button_menu;
    ASSERT_MALLOC(button, NULL);
    button = init_button((sfVector2f){60, 10}, (sfVector2f){35, 35}, blis,
    "assets/tools.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &open_button_menu;
    button = init_button((sfVector2f){110, 10}, (sfVector2f){35, 35}, blis,
    "assets/icon/circle-question.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &open_button_menu;
    return (button);
}

button_t *create_buttons(list_t *lis)
{
    button_t *button = NULL;

    for (int i = 0; i < 3; i++) {
        button = init_button((sfVector2f){0, 0}, (sfVector2f){0, 0}, lis, NULL);
        ASSERT_MALLOC(button, NULL);
    }
    button = create_menu_buttons(lis, button);
    ASSERT_MALLOC(button, NULL);
    button = init_button((sfVector2f){260, 10}, (sfVector2f){35, 35}, lis,
    "assets/icon/palette.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &open_color_menu;
    button = init_button((sfVector2f){160, 10}, (sfVector2f){35, 35}, lis,
    "assets/undo.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &undo;
    button = init_button((sfVector2f){210, 10}, (sfVector2f){35, 35}, lis,
    "assets/redo.png");
    return (button);
}
