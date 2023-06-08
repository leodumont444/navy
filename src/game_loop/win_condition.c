/*
** EPITECH PROJECT, 2023
** navy
** File description:
** win_condition
*/

#include "../../include/my.h"

int someone_won(items_t m)
{
    if (m->ally_touched >= 14){
        write(1, "Enemy won\n", 10);
        return 1;
    }
    if (m->ennemy_touched >= 14){
        write(1, "I won\n", 6);
        return 1;
    }
    return 0;
}
