/*
** EPITECH PROJECT, 2023
** MyPaint
** File description:
** text tools menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "button.h"
#include "my_window.h"
#include "my_string.h"

text_t *create_tool_text(list_t *color_text, text_t *text)
{
    text = create_text(" Size\n\n\n\nShapes\n\n\n\n Tool", 30,
    (sfVector2f){1730, 55}, text);
    ASSERT_MALLOC(text, NULL);
    color_text->intrf->append(color_text, text);
    return (text);
}

void draw_tool_text(sfText *text, sfRenderWindow *window, brush_t *brush)
{
    char *str = NULL;
    int size = 33;

    str = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    str = my_strcat(str, " Size\n\n\n\nShapes\n\n\n\n Tool");
    if (brush->tool == SELECT)
        str = my_strcat(str, "\n\n None");
    if (brush->tool == EYEDROPPER)
        str = my_strcat(str, "\n\nPicker");
    if (brush->tool == BRUSH)
        str = my_strcat(str, "\n\nBrush");
    if (brush->tool == ERASER)
        str = my_strcat(str, "\n\nEraser");
    if (brush->tool == FILL)
        str = my_strcat(str, "\n\nBucket");
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, NULL);
    free(str);
}
