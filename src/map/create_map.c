/*
** EPITECH PROJECT, 2023
** navy
** File description:
** create map file
*/

#include "../../include/my.h"

int setup_map(items_t m)
{
    m->ally_map = malloc(sizeof(char *) * 9);
    m->ennemy_map = malloc(sizeof(char *) * 9);
    m->ally_map[8] = NULL, m->ennemy_map[8] = NULL;
    for (int i = 0; i < 8; i++){
        m->ally_map[i] = malloc(sizeof(char) * 9);
        m->ennemy_map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            m->ally_map[i][j] = '.', m->ennemy_map[i][j] = '.';
        m->ally_map[i][8] = '\0', m->ennemy_map[i][8] = '\0';
    }
    return 0;
}

int check_map_car(char *map, items_t m)
{
    char *template = ":~~:~~";
    for (int i = 0; i < 6; i++)
        if ((template[i] == ':' && map[i] != ':') ||
            (template[i] == '~' &&
            (i == 1 || i == 4) && (map[i] < 'A' || map[i] > 'H')) ||
            (template[i] == '~' &&
            (i == 2 || i == 5) && (map[i] < '1' || map[i] > '8')))
            return my_error("Error: Wrong map format", m);
    return 0;
}

int verify_map(items_t m)
{
    setup_map(m);
    char *map = my_strdup(m->file->text);
    for (int j = 2; j < 6; j++, map += 7){
        if (map[0] != j + '0')
            return my_error("Error: Wrong map format", m);
        map++;
        if (check_map_car(my_strdup(map), m) == 84)
            return 84;
    }
    for (int i = 0; i < 4; i++){
        if (put_boats(m) == 84)
            return 84;
        m->file->text += 8;
    }
    return 0;
}
