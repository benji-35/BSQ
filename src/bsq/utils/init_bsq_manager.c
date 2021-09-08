/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** init_bsq_manager
*/

#include "../../../includes/bsq_func.h"

void init_bsq_manager(bsq_manager_t *manager, text square)
{
    manager->result.size = -1;
    manager->result.pos.y = -1;
    manager->result.pos.x = -1;
    manager->current.size = -1;
    manager->current.pos.x = -1;
    manager->current.pos.y = -1;
    manager->square = square;
}