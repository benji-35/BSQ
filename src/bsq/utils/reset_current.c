/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** reset_current
*/

#include "../../../includes/bsq_func.h"

void reset_current_manager(bsq_manager_t *manager)
{
    if (manager->current.size < 1)
        return;
    if (manager->current.size > manager->result.size) {
        manager->result.size = manager->current.size;
        manager->result.pos.x = manager->current.pos.x;
        manager->result.pos.y = manager->current.pos.y;
    }
}