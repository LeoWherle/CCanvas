/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** brush_create
*/

#include <stdlib.h>
#include "canvas.h"
#include "colors.h"
#include "errorhandling.h"
#include "my_window.h"


/**
 * @brief Create a brush object
 * TEXTURE IS NOT LOADED HERE
 *
 * @return brush_t*
 */
brush_t *create_brush(void)
{
    brush_t *brush = malloc(sizeof(brush_t));

    if (!brush)
        return NULL;
    brush->size = 25;
    brush->color = Black;
    brush->tool = SELECT;
    brush->shape = CIRCLE;
    brush->active = 0;
    brush->help = 0;
    brush->help_menu = 0;
    brush->texture = NULL;
    brush->texture = malloc(sizeof(sfTexture *) * TOOL_AMOUNT);
    ASSERT_MALLOC(brush->texture, NULL)
    brush->sprite = sfSprite_create();
    ASSERT_MALLOC(brush->sprite, NULL)
    ASSERT_MALLOC(create_infos(brush), NULL)
    ASSERT_MALLOC(create_cursor(brush), NULL)
    return brush;
}

brush_t *brush_add_tool_path(brush_t *brush, char *path, tool_t tool)
{
    if (!brush || !path)
        return NULL;
    brush->texture[tool] = NULL;
    brush->texture[tool] = sfTexture_createFromFile(path, NULL);
    ASSERT_MALLOC(brush->texture[tool], NULL)
    return brush;
}

brush_t *brush_add_tool_texture(brush_t *brush, sfTexture *texture, tool_t tool)
{
    if (!brush || !texture)
        return NULL;
    brush->texture[tool] = texture;
    return brush;
}

brush_t *brush_create_all(void)
{
    brush_t *brush = create_brush();

    if (!brush)
        return NULL;
    brush = brush_add_tool_path(brush, "assets/brush.png", BRUSH);
    ASSERT_MALLOC(brush, NULL)
    brush = brush_add_tool_path(brush, "assets/eraser.png", ERASER);
    ASSERT_MALLOC(brush, NULL)
    brush = brush_add_tool_path(brush, "assets/fill.png", FILL);
    ASSERT_MALLOC(brush, NULL)
    brush = brush_add_tool_path(brush, "assets/eyedropper.png", EYEDROPPER);
    ASSERT_MALLOC(brush, NULL)
    brush = brush_add_tool_path(brush, "assets/selector.png", SELECT);
    ASSERT_MALLOC(brush, NULL)
    return brush;
}

// sfSprite_destroy(brush->sprite);
// for (; i < TOOL_AMOUNT; i++)
//     free(brush->texture[i]);
// sfTexture_destroy(brush->texture);
void destroy_brush(brush_t *brush)
{
    UNUSED int i = 0;

    if (!brush)
        return;
    sfCircleShape_destroy(brush->circle);
    sfRectangleShape_destroy(brush->rect);
    sfText_destroy(brush->help_text);
    sfFont_destroy(brush->font);
    sfSprite_destroy(brush->help_sprite);
    sfTexture_destroy(brush->help_texture);
    free(brush->texture);
    free(brush);
}
