/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** include all my functions of libmy.a
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdint.h>
    struct mod {
        int padding;
        int precision;
        char pad;
        int nbr;
        int i;
        char plus;
        char hashtag;
        char space;
    };
    typedef struct linked_list{
        int data;
        struct linked_list *next;
        struct linked_list *prev;
    }llist;
    typedef llist *l_list;
    char *my_strcat(char const *dest, char const *src);
    char *my_revstr(char *str);
    unsigned int my_putchar(char c);
    unsigned int my_intlen(long int c);
    unsigned int my_put_nbr(int nb);
    unsigned int my_putstr(char const *str);
    unsigned int my_strlen(char const *str);
    unsigned int my_compute_power_rec(int nbr, int p);
    unsigned int my_printf(char const *str, ...);
    unsigned int my_putchar_arg(va_list ap, struct mod modif);
    unsigned int my_put_pourcent(va_list ap, struct mod modif);
    unsigned int my_put_nbr_arg(va_list ap, struct mod modif);
    unsigned int my_put_octal(va_list ap, struct mod modif);
    unsigned int my_put_unsigned(va_list ap, struct mod modif);
    unsigned int my_putstr_arg(va_list ap, struct mod modif);
    unsigned int my_put_hexa(va_list ap, struct mod modif);
    unsigned int my_put_hexa_maj(va_list ap, struct mod modif);
    unsigned int my_put_pointer(va_list ap, struct mod modif);
    unsigned int my_put_binary_unsigned(va_list ap,
    __attribute__((unused)) struct mod modif);
    unsigned int my_put_string_octal(va_list ap, struct mod modif);
    unsigned int my_put_float_f(va_list ap, struct mod modif);
    unsigned int my_print_scient(va_list ap, struct mod modif);
    unsigned int my_print_scient_maj(va_list ap, struct mod modif);
    unsigned int my_put_g_gen(va_list ap, struct mod modif);
    struct mod detect_n(char const *str, va_list ap, struct mod modif);
    struct mod detect_p(char const *str, va_list ap, struct mod modif);
    unsigned int my_is_known_flag(char c);
    unsigned int my_is_num(char c);
    unsigned int my_put_g_genbis(va_list ap, struct mod modif);
    unsigned int print_space(struct mod modif, long double nbr);
    unsigned int my_put_float_g(double nbr, int prec, struct mod modif);
    int my_get_padding(char const *str, int ind, va_list ap);
    unsigned int my_get_precision(char const *str, int index, va_list ap);
    unsigned int my_put_base(unsigned long long n, char const *base);
    char *my_strncpy(char *dest, char const *src, unsigned int n);
    char *my_strdup(char const *src);
    int my_strncmp(char *a, char *b, int n);
    l_list create(int data);
    l_list delete_begin(l_list list);
    l_list insert_end(int data, l_list list);
    l_list insert_begin(int data, l_list list);
    int my_strisnum(char *str);
    int get_nbr(char *str);
#endif
