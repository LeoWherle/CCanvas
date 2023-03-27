/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas
*/

#ifndef CANVAS_H_
    #define CANVAS_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stddef.h>

    #define WIDTH 1920
    #define HEIGHT 1080

    typedef struct brush_s brush_t;
    typedef struct canvas_s canvas_t;
    typedef unsigned int uint;
    // Typedef to draw a shape
    typedef void (*shape_ft)(sfVector2i, sfVector2i, canvas_t *, brush_t *);

    typedef union pixel_s {
        // from 0x00000000 to 0xFFFFFFFF
        sfUint32 rgba;
        // from 0x00 to 0xFF
        sfUint8 r;
        // from 0x00 to 0xFF
        sfUint8 g;
        // from 0x00 to 0xFF
        sfUint8 b;
        // from 0x00 to 0xFF
        sfUint8 a;
    } pixel_t;

    typedef enum shape_e {
        SQUARE,
        CIRCLE
    } shape_t;

    typedef enum tool_e {
        BRUSH,
        ERASER,
        FILL,
        EYEDROPPER,
        SELECT,
        TOOL_AMOUNT
    } tool_t;

    typedef struct brush_s {
        int active;
        tool_t tool;
        shape_t shape;
        uint size;
        sfUint32 color;
        sfTexture **texture;
        sfSprite *sprite;
        sfText *help_text;
        sfFont *font;
        int help;
        int help_menu;
        sfSprite *help_sprite;
        sfTexture *help_texture;
        sfVector2i old_pos;
        sfCircleShape *circle;
        sfRectangleShape *rect;
    } brush_t;

    typedef struct canvas_s {
        int width;
        int height;
        sfVector2f pos;
        // pixels is a 1D array of pixels (1 * 4 bytes per pixel)
        pixel_t *pixels;
        sfTexture *texture;
        sfSprite *sprite;
        int help_menu;
    } canvas_t;

    canvas_t *create_canvas(unsigned int width, unsigned int height);
    void destroy_canvas(canvas_t *canvas);

    void fill_canvas(canvas_t *canvas, sfColor color);
    void fill_canvas_hex(canvas_t *canvas, sfUint32 color);

    void set_pixel(uint x, uint y, canvas_t *canvas, sfUint32 color);
    void set_pixel_color(pixel_t pixel, sfUint32 color);
    void get_pixel_color(pixel_t pixel, sfUint32 color);

    void display_canvas(sfRenderWindow *window, canvas_t *canvas);

    int get_bot(sfVector2i pos, uint sze, canvas_t *canvas);
    int get_top(sfVector2i pos, uint size, canvas_t *canvas);
    int get_left(sfVector2i pos, uint size, canvas_t *canvas);
    int get_right(sfVector2i pos, uint size, canvas_t *canvas);

    brush_t *create_brush(void);
    brush_t *create_infos(brush_t *brush);
    void destroy_brush(brush_t *brush);

void draw_circle(sfVector2i pos, sfVector2i pix, canvas_t *cnvs, brush_t *brsh);
void draw_square(sfVector2i pos, sfVector2i pix, canvas_t *cnvs, brush_t *brsh);

void draw_shape(sfVector2i pos, canvas_t *canvas, brush_t *brush, shape_ft fun);
void draw(sfRenderWindow *window, canvas_t *canvas, brush_t *brush);
void draw_smooth_line(sfRenderWindow *window, sfVector2i old_pos,
brush_t *brush, canvas_t *canvas);

void create_color_spectrum(sfUint32* buffer, uint width, uint height,
uint brightness);

    typedef struct canvas_module_s {
        canvas_t *(*create)(uint width, uint height);
        void (*destroy)(canvas_t *canvas);
        void (*fill)(canvas_t *canvas, sfColor color);
    } canvas_module_t;

#endif /* !CANVAS_H_ */
