/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** bsq
*/

#include "../../includes/bsq_func.h"

static bool check_errors(int ac, text av, text *square)
{
    if (ac < 2)
        return true;
    *square = kopen_file_t(av[1]);
    if (*square == NULL) {
        kfprintf(2, "You have to put a good file\n");
        return true;
    }
    if (!file_is_good(*square)) {
        kfprintf(2, "The content of file is bad\n");
        free_text(*square);
        return true;
    }
    return false;
}

int bsq_resolve(int ac, text av)
{
    text square;
    bsq_manager_t manager;
    
    if (check_errors(ac, av, &square)) {
        return 84;
    }
    remove_line_text(&square, 0);
    init_bsq_manager(&manager, square);
    for (ksize_t y = 0; y < length_text(square); y++) {
        for (ksize_t x = 0; x < length(square[y]); x++) {
            step_checking(&manager, x, y);
            reset_current_manager(&manager);
        }
    }
    display_bsq(&manager);
    return 0;
}