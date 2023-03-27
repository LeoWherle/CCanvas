/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** open file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_window.h"
#include "my_string.h"
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "errorhandling.h"
#include "colors.h"

static int show_instructions(void)
{
    sfText *text = NULL;
    sfFont *font = NULL;
    sfRenderWindow *window = create_window(NULL);
    char msg[] = "Follow the instructions in the terminal to open your file";

    text = sfText_create();
    ASSERT_MALLOC(text, 84);
    font = sfFont_createFromFile("assets/font.ttf");
    ASSERT_MALLOC(font, 84);
    sfText_setFont(text, font);
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){350, 10});
    sfText_setColor(text, sfRed);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfText_destroy(text);
    sfFont_destroy(font);
    return (0);
}

static int detect_extension(char *name, int len)
{
    if (len < 5) {
        write(2, "Error: Invalid file\nGo back to the MyPaint Window\n", 50);
        return (1);
    }
    if (my_strcmp(name + len - 5, ".png") == 0)
        return (0);
    if (my_strcmp(name + len - 5, ".jpg") == 0)
        return (0);
    if (my_strcmp(name + len - 5, ".bmp") == 0)
        return (0);
    write(2, "Error: Invalid file\nGo back to the MyPaint Window\n", 50);
    return (1);
}

static void write_open_file(void)
{
    write(1, "Welcome to the file manager.\nYou can open a .jpg file,", 55);
    write(1, " a .png file or a .bmp file\nEnter the path of the file: ", 56);
}

void open_the_image(sfImage *image, const sfUint8 *pixels, char *name,
canvas_t *canva)
{
    sfRenderWindow *window = create_window(NULL);

    if (image == NULL) { write(2, "Go back to the MyPaint Window\n", 30);
        return;
    }
    if (sfImage_getSize(image).x > 1660 || sfImage_getSize(image).y > 1000) {
        write(2, "Error: image too big, max size is 1600x1000\n", 44);
        write(2, "Go back to the MyPaint Window\n", 30);
        return;
    }
    pixels = sfImage_getPixelsPtr(image);
    if (pixels == NULL)
        return;
    fill_canvas_hex(canva, Transparent);
    display_canvas(window, canva);
    canva->pixels = (pixel_t *)pixels;
    canva->height = sfImage_getSize(image).y;
    canva->width = sfImage_getSize(image).x;
    free(name);
    write(1, "File opened !\n", 14);
}

void open_image(UNUSED button_t *button, UNUSED node_t *b_list,
UNUSED brush_t *brush, UNUSED canvas_t *canva)
{
    sfImage *image = NULL;
    const sfUint8 *pixels = NULL;
    size_t size = 100;
    int len = 0;
    char *name = NULL;

    if (show_instructions() == 84) {
        write(2, "Error: Failed to load font\n", 27);
        return;
    }
    write_open_file();
    len = getline(&name, &size, stdin);
    if (len == -1)
        return;
    write(1, "Opening...\n", 11);
    name[len - 1] = '\0';
    if (detect_extension(name, len) == 1)
        return;
    image = sfImage_createFromFile(name);
    open_the_image(image, pixels, name, canva);
}
