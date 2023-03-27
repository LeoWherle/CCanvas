/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** Save canva manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_window.h"
#include "my_string.h"
#include "chained_list.h"
#include "button.h"
#include "canvas.h"
#include "errorhandling.h"

static int show_instructions(void)
{
    sfText *text = NULL;
    sfFont *font = NULL;
    sfRenderWindow *window = create_window(NULL);
    char msg[] = "Follow the instructions in the terminal to save your file";

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
    if (len < 5)
        return (1);
    if (my_strcmp(name + len - 5, ".png") == 0)
        return (0);
    if (my_strcmp(name + len - 5, ".jpg") == 0)
        return (0);
    if (my_strcmp(name + len - 5, ".bmp") == 0)
        return (0);
    return (1);
}

static void write_save_manager(void)
{
    write(1, "Welcome to the save manager.\nYou can save your file as a", 57);
    write(1, " .jpg (default extension if you don't write one) ", 49);
    write(1, "or a .png or a .bmp\nEnter the name of the file: ", 49);
}

void save_canva(UNUSED button_t *button, UNUSED node_t *b_list, UNUSED
brush_t *brush, canvas_t *canva)
{
    sfImage *image = NULL;
    char *name = NULL;
    size_t size = 100;
    int len = 0;

    if (show_instructions() == 84) {
        write(2, "Error: Failed to load font\n", 27);
        return;
    }
    image = sfImage_createFromPixels(canva->width, canva->height,
    (sfUint8 *)canva->pixels);
    write_save_manager();
    len = getline(&name, &size, stdin);
    if (len == -1) return;
    write(1, "Saving...\n", 10);
    name[len - 1] = '\0';
    if (detect_extension(name, len) == 1)
        name = my_strcat(name, ".jpg");
    if (sfImage_saveToFile(image, name) == sfTrue)
        write(1, "Saved!\n", 7);
}
