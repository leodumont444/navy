/*
** EPITECH PROJECT, 2023
** navy
** File description:
** print_map
*/

#include "../../include/my.h"

void print_map(items_t m)
{
    my_printf("my positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++){
        my_printf("%d|", i + 1);
        for (int j = 0; j < 7; j++)
            my_printf("%c ", m->ally_map[i][j]);
        my_printf("%c\n", m->ally_map[i][7]);
    }
    my_printf("\nenemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++){
        my_printf("%d|", i + 1);
        for (int j = 0; j < 7; j++)
            my_printf("%c ", m->ennemy_map[i][j]);
        my_printf("%c\n", m->ennemy_map[i][7]);
    }
    my_printf("\n");
}

void update_map(items_t m, char *co)
{
    int status = get_status(2);
    char old = m->ennemy_map[co[1] - 1][co[0] - 1];

    m->ennemy_map[co[1] - 1][co[0] - 1] =
        (status == 1 || old == 'x') ? 'x' : 'o';
    m->ennemy_touched += (status == 1 && old != 'x') ? 1 : 0;
}
