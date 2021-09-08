/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <kap/klib.h>

typedef struct check_square_s check_square_t;
typedef struct bsq_manager_s bsq_manager_t;
typedef struct vector2_s vector2_t;

struct vector2_s {
    ksize_t x;
    ksize_t y;
};

struct check_square_s {
    ksize_t size;
    vector2_t pos;
};

struct bsq_manager_s {
    check_square_t result;
    check_square_t current;
    text square;
};

#endif /* !BSQ_H_ */
