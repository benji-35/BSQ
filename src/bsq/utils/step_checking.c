/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** step_checking
*/

#include "../../../includes/bsq_func.h"

static ksize_t get_curr_max_size(bsq_manager_t *manager, ksize_t x, ksize_t y)
{
    ksize_t max_x = length(manager->square[0]) - x;
    ksize_t max_y = length_text(manager->square) - y;

    if (max_x < max_y)
        return max_x;
    return max_y;
}

static bool check_can_do(cstring line, ksize_t x, ksize_t i)
{
    for (ksize_t _x = x; _x < x + i; _x++) {
        if (line[_x] != '.')
            return false;
    }
    return true;
}

static bool can_do_it(bsq_manager_t *manager, ksize_t x, ksize_t y, ksize_t i)
{
    for (ksize_t _y = y; _y < y + i; _y++) {
        if (!check_can_do(manager->square[_y], x, i)) {
            return false;
        }
    }
    return true;
}

void step_checking(bsq_manager_t *manager, ksize_t x, ksize_t y)
{
    ksize_t max_size = get_curr_max_size(manager, x, y) + 1;
    ksize_t curr_size = 0;

    for (ksize_t i = 1; i < max_size; i++) {
        if (!can_do_it(manager, x, y, i))
            break;
        curr_size = i;
    }
    manager->current.size = curr_size;
    manager->current.pos.x = x;
    manager->current.pos.y = y;
}