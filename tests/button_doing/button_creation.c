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
    button = create_button_image((sfVector2f){10, 10}, (sfVector2f){30, 35},
    blis, "assets/icon/file.png");
    button->is_clicked = &open_button_menu;
    button = create_button_image((sfVector2f){60, 10}, (sfVector2f){35, 35},
    blis, "assets/tools.png");
    button->is_clicked = &open_button_menu;
    button = create_button_image((sfVector2f){110, 10}, (sfVector2f){35, 35},
    blis, "assets/icon/circle-question.png");
    button->is_clicked = &open_button_menu;
    return (button);
}

button_t *create_buttons(list_t *lis)
{
    button_t *button = NULL;

    for (int i = 0; i < 2; i++) {
        button = create_button_image((sfVector2f){0, 0}, (sfVector2f){0, 0},
        lis, NULL);
        ASSERT_MALLOC(button, NULL);
    }
    button = create_menu_buttons(lis, button);
    ASSERT_MALLOC(button, NULL);
    button = create_button_image((sfVector2f){260, 10}, (sfVector2f){35, 35},
    lis, "assets/icon/palette.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &open_color_menu;
    button = create_button_image((sfVector2f){160, 10}, (sfVector2f){35, 35},
    lis, "assets/undo.png");
    ASSERT_MALLOC(button, NULL);
    button = create_button_image((sfVector2f){210, 10}, (sfVector2f){35, 35},
    lis, "assets/redo.png");
    return (button);
}

static button_t *create_file_menu(list_t *bli, list_t *temp, button_t *button)
{
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = create_button_image((sfVector2f){25, 60}, (sfVector2f){35, 50},
    temp, "assets/icon/file-image.png");
    ASSERT_MALLOC(button, NULL);
    button->is_clicked = &reset_canva;
    button = create_button_image((sfVector2f){15, 125}, (sfVector2f){40, 50},
    temp, "assets/icon/file-import.png");
    ASSERT_MALLOC(button, NULL);
    button = create_button_image((sfVector2f){25, 190}, (sfVector2f){40, 50},
    temp, "assets/icon/file-export.png");
    ASSERT_MALLOC(button, NULL);
    button = find_id(bli->head, 1);
    ASSERT_MALLOC(button, NULL);
    button->sub_b = temp;
    return (button);
}

static button_t *create_edit_menu(list_t *b_list, list_t *temp,
button_t *button)
{
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = create_button_image((sfVector2f){85, 60}, (sfVector2f){50, 50},
    temp, "assets/icon/paintbrush-solid.png");
    ASSERT_MALLOC(button, NULL);
    button = create_button_image((sfVector2f){85, 125}, (sfVector2f){50, 50},
    temp, "assets/icon/fill-drip.png");
    ASSERT_MALLOC(button, NULL);
    button = create_button_image((sfVector2f){85, 190}, (sfVector2f){45, 50},
    temp, "assets/icon/eraser.png");
    ASSERT_MALLOC(button, NULL);
    button = find_id(b_list->head, 2);
    ASSERT_MALLOC(button, NULL);
    button->sub_b = temp;
    return (button);
}

button_t *create_sub_buttons(list_t *b_list)
{
    list_t *temp = NULL;
    button_t *button = NULL;

    button = create_file_menu(b_list, temp, button);
    ASSERT_MALLOC(button, NULL);
    button = create_edit_menu(b_list, temp, button);
    ASSERT_MALLOC(button, NULL);
    temp = init_list();
    ASSERT_MALLOC(temp, NULL);
    button = create_button_image((sfVector2f){1700, 500},
    (sfVector2f){200, 200}, temp, "assets/color_selector.png");
    ASSERT_MALLOC(button, NULL);
    button = find_id(b_list->head, 4);
    ASSERT_MALLOC(button, NULL);
    button->sub_b = temp;
    return (button);
}
