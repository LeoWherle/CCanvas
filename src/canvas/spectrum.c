/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** spectrum
*/

#include <SFML/Graphics.h>
#include "canvas.h"

/**
 * @brief Create a color spectrum object
 *
 * @param buffer the buffer to fill
 * @param width the width of the buffer
 * @param height the height of the buffer
 * @param brightness from 0 to 255 (0 is black, 255 is white)
 */
void create_color_spectrum(sfUint32* buffer, uint width, uint height,
uint brightness)
{
    sfUint32 color = 0xff000000;
    uint y = 0;
    uint x = 0;
    float r = 0;
    float g = 0;
    float b = 0;
    brightness = brightness > 255 ? 255 : brightness;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            r = ((x / (float)(width - 1))) * brightness;
            g = (y / (float)(height - 1)) * brightness;
            b = (1.0 - (r / brightness)) * brightness;
            color = 0xff000000;
            color |= ((sfUint32)r << 16) & 0xff0000;
            color |= ((sfUint32)g << 8) & 0xff00;
            color |= (sfUint32)b & 0xff;
            buffer[y * width + x] = color;
        }
    }
}
