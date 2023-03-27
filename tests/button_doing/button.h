/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** structures
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "chained_list.h"
#include "canvas.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef enum gui_state_e {
    NONE = 0,
    HOVER = 1,
    PRESSED = 2,
    RELEASED = 3,
} gui_state_t;

typedef struct button_s {
    int id;
    gui_state_t state;
    sfBool open;
    sfVector2f pos;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfRectangleShape *image;
    sfText *text;
    list_t *sub_b;
    void (*is_clicked)(struct button_s *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void (*is_hover)(struct button_s *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
} button_t;

    button_t *create_button_image(sfVector2f pos, sfVector2f size, list_t *blis,
    char *img);
    void destroy_button(void *button);
    button_t *find_id(node_t *list, int id);
    button_t *create_buttons(list_t *lis);
    button_t *create_sub_buttons(list_t *sub);

    button_t *button_add_image(button_t *button, char *path, sfVector2f size,
    sfVector2f pos);
    button_t *button_add_text(button_t *button, char *text, sfFont *font,
    int padding_left);

    sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event);
    sfBool close_menu(button_t *button, sfMouseButtonEvent *ev);
    void open_button_menu(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void open_color_menu(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void reset_canva(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);

    sfBool is_button_hovered(button_t *button, sfMouseMoveEvent *event);
    void shade_button_color(button_t *button, node_t *b_list);

#endif /* !STRUCT_H_ */
