/*
** EPITECH PROJECT, 2021
** bsqRematered
** File description:
** checking_file
*/

#include "../../../includes/bsq_func.h"

static bool char_is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

static bool line_is_number(cstring str)
{
    for (ksize_t i = 0; i < length(str); i++) {
        if (!char_is_digit(str[i]))
            return false;
    }
    return true;
}

static bool check_validity_line(cstring line)
{
    for (ksize_t x = 0; x < length(line); x++) {
        if (line[x] != '.' && line[x] != 'o') {
            kprintf("Forbiden char in bsq : %c\n", line[x]);
            return false;
        }
    }
    return true;
}

bool file_is_good(text content)
{
    ksize_t curr_len = 0;
    ksize_t max_len = -1;
    if (content == NULL)
        return false;
    if (!line_is_number(content[0]))
        return false;
    for (ksize_t y = 1; y < length_text(content); y++) {
        curr_len = length(content[y]);
        if (!check_validity_line(content[y]))
            return false;
        if (curr_len == 0)
            return false;
        if (max_len < 0)
            max_len = curr_len;
        if (curr_len != max_len)
            return false;
    }
    return true;
}