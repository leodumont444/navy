/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include "./my_printf.h"
    #include <math.h>
    #include <signal.h>
    struct file_open{
        char *filepath;
        int fd;
        char *text;
        int len;
    };
    typedef struct file_open file_s;
    typedef file_s *file_t;
    struct options{
        file_t file;
        int error;
        int player;
        char *filepath;
        char **ennemy_map;
        char **ally_map;
        int pid;
        int ennemy_pid;
        int help;
        int ally_touched;
        int ennemy_touched;
    };
    typedef struct options opt;
    typedef opt *items_t;
    int init_file_struct(file_t file, char *filepath, int size, items_t m);
    void free_all(items_t m);
    int check_error(int ac, char **av, items_t m);
    int my_error(char *str, items_t m);
    int put_boats(items_t m);
    int verify_map(items_t m);
    int game_loop_ennemy(items_t m);
    int game_loop_host(items_t m);
    void send_sigusr(int pid, int usr);
    void update_map(items_t m, char *co);
    int get_status(int opt);
    int someone_won(items_t m);
    void print_map(items_t m);
    int attack(items_t m);
    int defend(items_t m);

#endif
