/*
** EPITECH PROJECT, 2023
** navy
** File description:
** defend
*/

#include "../../include/my.h"

void reply_miss_hit(items_t m, int c1, int c2)
{
    if (m->ally_map[c2][c1] != '.' && m->ally_map[c2][c1] != 'o' &&
        m->ally_map[c2][c1] != 'x'){
        my_printf("hit\n\n");
        m->ally_map[c2][c1] = 'x';
        send_sigusr(m->pid, 1);
        m->ally_touched++;
    } else {
        my_printf("missed\n\n");
        (m->ally_map[c2][c1] != 'x') ? m->ally_map[c2][c1] = 'o' : 0;
        send_sigusr(m->pid, 2);
    }
}

int get_coords(int signal)
{
    static int coord_1 = 0;
    static int coord_2 = 0;
    static int ping = 0;
    int temp = ping;

    coord_1 += (signal == 1 && ping == 0) ? 1 : 0;
    coord_2 += (signal == 1 && ping == 1) ? 1 : 0;
    ping += (signal == 2) ? 1 : 0;
    if (signal == -1){
        coord_1 = 0;
        coord_2 = 0;
        ping = 0;
        return temp;
    }
    if ((signal == 0 && ping >= 2) ||
        (signal == 0 && coord_1 == 0 && coord_2 == 0 && ping == 1))
        return 0;
    if (signal == 3 || signal == 4)
        return (signal == 3) ? coord_1 : coord_2;
    return 1;
}

void signal_coord1(int signum)
{
    get_coords(1);
}

void signal_coord2(int signum)
{
    get_coords(2);
}

int defend(items_t m)
{
    char coords[3];
    int c1;
    int c2;

    my_printf("waiting for enemy's attack...\n");
    signal(SIGUSR1, signal_coord1);
    signal(SIGUSR2, signal_coord2);
    while (get_coords(0));

    c1 = get_coords(3) - 1;
    c2 = get_coords(4) - 1;

    if (get_coords(-1) == 1)
        return 84;

    coords[2] = '\0', coords[0] = '@' + c1 + 1, coords[1] = '0' + c2 + 1;

    my_printf("%s: ", coords);
    reply_miss_hit(m, c1, c2);
    return 1;
}
