/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** bsq_func
*/

#ifndef BSQ_FUNC_H_
#define BSQ_FUNC_H_

#include "bsq.h"

extern int bsq_resolve(int ac, text av);
extern void init_bsq_manager(bsq_manager_t *manager, text square);
extern void display_bsq(bsq_manager_t *manager);
extern void reset_current_manager(bsq_manager_t *manager);
extern void step_checking(bsq_manager_t *manager, ksize_t x, ksize_t y);
extern bool file_is_good(text content);

#endif /* !BSQ_FUNC_H_ */
