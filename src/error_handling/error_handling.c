/*
** EPITECH PROJECT, 2023
** navy
** File description:
** error handling
*/

#include "../../include/my.h"

int my_error(char *str, items_t m)
{
    write(2, str, my_strlen(str));
    free_all(m);
    return 84;
}

int help(int ac, char ** av, items_t m)
{
    m->help = 0;
    if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        my_printf("USAGE\n       ./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n       first_player_pid: only for the 2nd");
        my_printf(" player. pid of the first player. \n       navy_");
        my_printf("positions: file representing the positions of the ships.\n");
        m->help = 1;
        return 1;
    }
    return 0;
}

int check_error(int ac, char **av, items_t m)
{
    if (help(ac, av, m) == 1)
        return 1;
    if ((ac != 3 && ac != 2) || (ac == 3 && my_strisnum(av[1]) == 0))
        return my_error("Error: Something wrong with arguments", m);

    if (ac == 3)
        m->filepath = my_strdup(av[2]), m->player = 2, m->pid = get_nbr(av[1]);
    else
        m->filepath = my_strdup(av[1]), m->player = 1;
    return 0;
}
