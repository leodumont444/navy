/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main file
*/

#include "../include/my.h"


int (*game_loop[3])(items_t) = {'\0', &game_loop_host, &game_loop_ennemy};

int main(int ac, char **av)
{
    items_t m = malloc(sizeof(opt));
    int win = 0;
    if (check_error(ac, av, m) == 84)
        return 84;

    if (m->help == 1)
        return 0;

    if (init_file_struct(m->file, m->filepath, 32, m) == 84)
        return 84;

    if (verify_map(m) == 84)
        return 84;

    if (game_loop[m->player](m) == 84)
        return 84;

    win = (m->ally_touched >= 14) ? 1 : 0;
    free_all(m);
    return win;
}
