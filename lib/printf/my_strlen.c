/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

#include <string.h>

unsigned int my_strlen(char const * str )
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}
