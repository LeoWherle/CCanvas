/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** pixel_color
*/

#include <SFML/Graphics.h>
#include "canvas.h"
#include "errorhandling.h"

/**
 * @brief Set the pixel color object
 *
 * @param pixel the pixel to set the color to
 * @param color the color to set
 */
inline void set_pixel_color(pixel_t pixel, UNUSED sfUint32 color)
{
    pixel.rgba |= color << 24;
    pixel.rgba |= color << 16;
    pixel.rgba |= color << 8;
    pixel.rgba |= color << 0;
}

/**
 * @brief Get the pixel color object
 *
 * @param pixel the pixel to get the color from
 * @param color the color to set
 */
inline void get_pixel_color(pixel_t pixel, UNUSED sfUint32 color)
{
    color = (pixel.rgba >> 24) & 0xFF;
    color = (pixel.rgba >> 16) & 0xFF;
    color = (pixel.rgba >> 8) & 0xFF;
    color = (pixel.rgba >> 0) & 0xFF;
}
