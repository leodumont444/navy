/*
** EPITECH PROJECT, 2023
** navy
** File description:
** game_loop_ennemy
*/

#include "../../include/my.h"

int is_not_connected(int connected)
{
    static int connected1 = 0;
    if (connected != 0 || connected1 != 0)
        connected1++;
    else
        return 1;
    return 0;
}

void sig_handler_connection(int signum)
{
    is_not_connected(1);
}

void connect_ennemy(items_t m)
{
    int connected = 0;

    send_sigusr(m->pid, 1);

    my_printf("my_pid: %d\n", getpid());

    signal(SIGUSR1, sig_handler_connection);

    while (is_not_connected(connected));

    my_printf("successfully connected\n\n");
}

int game_loop_ennemy(items_t m)
{
    m->ally_touched = 0;
    m->ennemy_touched = 0;

    connect_ennemy(m);
    while (!someone_won(m)){
        print_map(m);
        if (defend(m) == 84)
            return 84;
        if (attack(m) == 84)
            return 84;
    }
    return 1;
}
