/*
** EPITECH PROJECT, 2023
** navy
** File description:
** place_boats
*/

#include "../../include/my.h"

int place_boat_number(items_t m, int nbr1, int nbr2, int letter)
{
    int number = nbr2 - nbr1 + 1;
    for (int i = nbr1; i <= nbr2; i++){
        if (m->ally_map[i][letter] != '.')
            return my_error("Wrong map format : 2 ship on same coords", m);
        m->ally_map[i][letter] = number + '0';
    }
    return 0;
}

int place_boat_letter(items_t m, int letter1, int letter2, int nbr)
{
    int number = letter2 - letter1 + 1;
    for (int i = letter1; i <= letter2; i++){
            if (m->ally_map[nbr][i] != '.')
                return my_error("Wrong map format : 2 ship on same coords", m);
            m->ally_map[nbr][i] = number + '0';
        }
    return 0;
}

int put_boats(items_t m)
{
    char *line = malloc(sizeof(char) * 8);
    my_strncpy(line, m->file->text, 7);
    char number = line[0] - '0';
    line++;
    int nbr1 = line[2] - '1', nbr2 = line[5] - '1';
    int letter1 = line[1] - 'A', letter2 = line[4] - 'A';

    if ((nbr1 != nbr2 && letter1 != letter2) ||
        ((letter2 - letter1) + (nbr2 - nbr1) + 1) != number)
        return my_error("Error: Wrong map format", m);
    if (nbr1 != nbr2)
        return place_boat_number(m, nbr1, nbr2, letter1) == 84;
    return (place_boat_letter(m, letter1, letter2, nbr1) == 84);
}
