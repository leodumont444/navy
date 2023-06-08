/*
** EPITECH PROJECT, 2023
** navy
** File description:
** game_loop_host
*/

#include "../../include/my.h"

int get_pid(int get, items_t m, int pid)
{
    static int pid_store = 0;

    if (get == 1 && pid_store == 0)
        return 1;
    if (get == 0)
        pid_store = (int)pid;
    else
        m->pid = pid_store;
    return 0;
}

void sig_handler_connect(int sig, siginfo_t *info, void *ucontext)
{
    get_pid(0, NULL, info->si_pid);
}

void connect_host(items_t m)
{
    m->pid = 0;
    struct sigaction act;

    act.sa_sigaction = &sig_handler_connect;
    act.sa_flags = SA_SIGINFO;

    sigemptyset(&(act.sa_mask));
    sigaction(SIGUSR1, &act, NULL);

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");

    while (get_pid(1, m, 0));

    my_printf("enemy connected\n\n");
    send_sigusr(m->pid, 1);
}

int game_loop_host(items_t m)
{
    m->ally_touched = 0;
    m->ennemy_touched = 0;

    connect_host(m);
    while (!someone_won(m)){
        print_map(m);
        if (attack(m) == 84)
            return 84;
        if (defend(m) == 84)
            return 84;
    }
    return 1;
}
