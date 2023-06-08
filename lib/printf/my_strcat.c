/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char const *dest, char const *src)
{
    int i = 0;
    int size_all = my_strlen(dest) + my_strlen(src);
    char *str = malloc(sizeof(char) * size_all + 1);
    for (int j = 0; dest[j]; j++, i++)
        str[i] = dest[j];
    for (int j = 0; src[j]; j++, i++)
        str[i] = src[j];
    str[size_all] = '\0';
    return str;
}
