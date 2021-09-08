/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** display_bsq
*/

#include "../../../includes/bsq_func.h"

static void complete_square_display(bsq_manager_t *manager)
{
    ksize_t y_max = manager->result.pos.y;
    ksize_t x_max = manager->result.pos.x;
    ksize_t size = manager->result.size;

    if (size < 1)
        return;
    for (ksize_t y = y_max; y < (y_max + size); y++) {
        for (ksize_t x = x_max; x < (x_max + size); x++) {
            manager->square[y][x] = 'X';
        }
    }
}

void display_bsq(bsq_manager_t *manager)
{
    if (manager == NULL || manager->square == NULL)
        return;
    complete_square_display(manager);
    my_puttext(manager->square, 1);
    free_text(manager->square);
}