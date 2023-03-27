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
    sfRectangleShape *rect;
    sfTexture *texture;
    list_t *sub_b;
    void (*is_clicked)(struct button_s *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void (*is_hover)(struct button_s *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    gui_state_t state;
    sfVector2f start;
    sfBool open;
} button_t;

    button_t *init_button(sfVector2f pos, sfVector2f size, list_t *blis,
    char *img);
    void destroy_button(void *button);
    node_t *find_id(node_t *list, int id);
    button_t *create_buttons(list_t *lis);
    button_t *create_sub_buttons(list_t *sub);
    button_t *create_color_menu_rg(list_t *temp, button_t *button);
    list_t *create_color_text_list(list_t *color_text);

    sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *event);
    sfBool close_menu(button_t *button, sfMouseButtonEvent *ev);
    void open_button_menu(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void open_color_menu(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void reset_canva(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void set_eraser(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void set_brush(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void set_picker(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void set_fill(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void increase_size(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void decrease_size(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void save_canva(button_t *button, node_t *b_list, brush_t *brush,
    canvas_t *canva);
    void increase_red(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void decrease_red(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void increase_green( button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void decrease_green(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void increase_blue(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void decrease_blue(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void increase_alpha(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void decrease_alpha( button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void display_info(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void display_help(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void undo(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void open_brush_menu(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void set_square_shape(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void set_circle_shape(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);
    void open_image(button_t *button, node_t *b_list,
    brush_t *brush, canvas_t *canva);

    sfUint32 get_color(const uint x, const uint y, const canvas_t *canvas);
    sfBool is_button_hovered(button_t *button, sfMouseMoveEvent *event);
    void shade_button_color(button_t *button, node_t *b_list);

#endif /* !STRUCT_H_ */
