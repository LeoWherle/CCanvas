/*
** EPITECH PROJECT, 2023
** mypaint [WSL: fedora]
** File description:
** canvas_modules
*/

#include "canvas.h"

const struct canvas_module_s Canvas = {
.create = create_canvas,
.destroy = destroy_canvas,
.fill = fill_canvas,
};
