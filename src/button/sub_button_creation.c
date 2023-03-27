/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** sub buttons creation
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "button.h"
#include "chained_list.h"
#include "errorhandling.h"

static button_t *create_file_menu(list_t *bli, list_t *temp, button_t *button)
{
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = init_button((sfVector2f){40, 60}, (sfVector2f){35, 50}, temp,
    "assets/icon/file-image.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &reset_canva;
    button = init_button((sfVector2f){30, 125}, (sfVector2f){40, 50}, temp,
    "assets/icon/file-import.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = open_image;
    button = init_button((sfVector2f){40, 190}, (sfVector2f){40, 50}, temp,
    "assets/icon/file-export.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = save_canva;
    button = find_id(bli->head, 1)->data;
    button->sub_b = temp;
    return (button);
}

static button_t *create_resizer(list_t *temp, button_t *button, list_t *b_list)
{
    ASSERT_MALLOC(temp, NULL);
    button = init_button((sfVector2f){1825, 100}, (sfVector2f){45, 45}, temp,
    "assets/icon/plus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &increase_size;
    button = init_button((sfVector2f){1725, 100}, (sfVector2f){45, 45}, temp,
    "assets/icon/minus.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &decrease_size;
    button = init_button((sfVector2f){1725, 225}, (sfVector2f){60, 60}, temp,
    "assets/icon/circle.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_circle_shape;
    button = init_button((sfVector2f){1825, 225}, (sfVector2f){60, 60}, temp,
    "assets/icon/square.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_square_shape;
    button = find_id(b_list->head, -2)->data;
    button->sub_b = temp;
    return (button);
}

static button_t *create_edit_menu(list_t *b_list, list_t *temp,
button_t *button)
{
    ASSERT_MALLOC(temp, NULL);
    button = init_button((sfVector2f){85, 60}, (sfVector2f){50, 50}, temp,
    "assets/icon/paintbrush-solid.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_brush;
    button = init_button((sfVector2f){85, 125}, (sfVector2f){50, 50}, temp,
    "assets/icon/fill-drip.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_fill;
    button = init_button((sfVector2f){85, 190}, (sfVector2f){45, 50}, temp,
    "assets/icon/eraser.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_eraser;
    button = init_button((sfVector2f){85, 255}, (sfVector2f){45, 50}, temp,
    "assets/icon/eye-dropper.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &set_picker;
    button = find_id(b_list->head, 2)->data;
    button->sub_b = temp;
    return (button);
}

static button_t *create_help_menu(list_t *b_list, list_t *temp,
button_t *button)
{
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = init_button((sfVector2f){130, 65}, (sfVector2f){50, 50}, temp,
    "assets/icon/circle-info.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &display_info;
    button = init_button((sfVector2f){130, 130}, (sfVector2f){50, 50}, temp,
    "assets/icon/circle-question.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &display_help;
    button = find_id(b_list->head, 3)->data;
    button->sub_b = temp;
    return (button);
}

button_t *create_sub_buttons(list_t *b_list)
{
    list_t *temp = NULL;
    button_t *button = NULL;

    button = create_file_menu(b_list, temp, button);
    ASSERT_MALLOC(button, NULL);
    temp = init_list();
    button = create_edit_menu(b_list, temp, button);
    ASSERT_MALLOC(button, NULL);
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = init_button((sfVector2f){1725, 875}, (sfVector2f){150, 150}, temp,
    NULL);
    ASSERT_MALLOC(button, NULL);
    ASSERT_MALLOC(create_color_menu_rg(temp, button), NULL);
    button = find_id(b_list->head, 4)->data;
    button->sub_b = temp;
    temp = init_list();
    ASSERT_MALLOC(create_resizer(temp, button, b_list), NULL);
    ASSERT_MALLOC(create_help_menu(b_list, temp, button), NULL);
    return (button);
}
