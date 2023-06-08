/*
** EPITECH PROJECT, 2023
** navy
** File description:
** attack_defend
*/

#include "../../include/my.h"

int get_status(int opt)
{
    static int retrn = 0;
    int temp = 0;

    if (opt == 0)
        return (retrn == 0) ? 1 : 0;
    if (opt == 2){
        temp = retrn;
        retrn = 0;
        return temp;
    }
    retrn = opt;
    return 0;
}

void get_signal_missed(int signum)
{
    get_status(-1);
    write(1, "missed\n\n", 8);
}

void get_signal_hit(int signum)
{
    get_status(1);
    write(1, "hit\n\n", 5);
}

void send_coords(items_t m, char *coords)
{
    coords[0] -= '@';
    coords[1] -= '0';

    for (int i = 0; i < coords[0]; i++)
        send_sigusr(m->pid, 1);

    send_sigusr(m->pid, 2);

    for (int i = 0; i < coords[1]; i++)
        send_sigusr(m->pid, 1);

    send_sigusr(m->pid, 2);
}

int attack(items_t m)
{
    size_t size = 3;
    char *co = malloc(sizeof(char) * 3);
    signal(SIGUSR1, get_signal_hit), signal(SIGUSR2, get_signal_missed);
    my_printf("attack: ");
    if (getline(&co, &size, stdin) == -1){
        send_sigusr(m->pid, 2);
        return 84;
    }
    while (my_strlen(co) != 3 || co[0] > 'H' || co[0] < 'A' || co[1] < '1' ||
        co[1] > '8'){
        my_printf("wrong position\nattack: ");
        getline(&co, &size, stdin);
    }
    co[2] = '\0';
    my_printf("%s: ", co);
    send_coords(m, co);
    while (get_status(0));
    update_map(m, co);
    free(co);
    return 1;
}
