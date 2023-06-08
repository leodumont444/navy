/*
** EPITECH PROJECT, 2023
** navy
** File description:
** lib
*/

#include "../../include/my.h"

void send_sigusr(int pid, int usr)
{
    usleep(20000);
    kill(pid, (usr == 1) ? SIGUSR1 : SIGUSR2);
}
