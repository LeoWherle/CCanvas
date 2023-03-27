/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas_create
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"

static pixel_t *create_pixel_array(unsigned int width, unsigned int height)
{
    pixel_t *pixels = NULL;

    pixels = malloc(width * height * sizeof(pixel_t));
    ASSERT_MALLOC(pixels, NULL)
    return (pixels);
}

canvas_t *create_canvas(unsigned int width, unsigned int height)
{
    canvas_t *canvas = NULL;
    sfUint32 *pixels = NULL;

    canvas = malloc(sizeof(canvas_t));
    ASSERT_MALLOC(canvas, NULL)
    canvas->width = width;
    canvas->height = height;
    canvas->pos = (sfVector2f){20, 50};
    canvas->pixels = create_pixel_array(width, height);
    ASSERT_MALLOC(canvas->pixels, NULL)
    fill_canvas_hex(canvas, White);
    pixels = (sfUint32 *)canvas->pixels;
    create_color_spectrum(pixels, width, height, 255);
    canvas->texture = sfTexture_create(width, height);
    ASSERT_MALLOC(canvas->texture, NULL)
    canvas->sprite = sfSprite_create();
    ASSERT_MALLOC(canvas->sprite, NULL)
    sfSprite_setPosition(canvas->sprite, (sfVector2f)canvas->pos);
    return (canvas);
}

void destroy_canvas(canvas_t *canvas)
{
    sfTexture_destroy(canvas->texture);
    sfSprite_destroy(canvas->sprite);
    free(canvas->pixels);
    free(canvas);
}
