/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** my_window functions
*/

#include "button.h"

#ifndef MY_WINDOW_H_
    #define MY_WINDOW_H_
    #define UNUSED __attribute__((unused))

typedef struct bg_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfRenderWindow *window;
} bg_t;

typedef struct text_s {
    sfTexture *texture;
    sfText *str;
    sfFont *font;
    int type;
    int color_type;
} text_t;

    sfRenderWindow *create_window(char *env[]);
    void destroy_bg(bg_t *bg);
    void resize_elements(bg_t *bg, list_t *b_list, brush_t *brush,
    canvas_t *canva);
    bg_t *create_background(bg_t *bg, sfRenderWindow *window);
    text_t *create_text(char *str, int size, sfVector2f pos, text_t *text);
    void destroy_text(void *text);
    void draw_text(sfRenderWindow *window, list_t *color_text, brush_t *brush);
    void display_help_menu(sfRenderWindow *window, brush_t *brush);
    void draw_side_menus(sfRenderWindow *window, button_t *button,
    brush_t *brush, list_t *color_text);
    text_t *create_tool_text(list_t *color_text, text_t *text);
    void draw_tool_text(sfText *text, sfRenderWindow *window, brush_t *brush);
    sfCircleShape *create_cursor(brush_t *brush);
    void draw_cursor(sfRenderWindow *window, brush_t *brush, canvas_t *canva);

#endif /* MY_WINDOW_H_ */
