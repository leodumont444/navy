/*
** EPITECH PROJECT, 2023
** navy
** File description:
** file with free functions
*/

#include "../../include/my.h"

void free_all(items_t m)
{
    if (m->file)
        free(m->file);
    if (m)
        free(m);
}
