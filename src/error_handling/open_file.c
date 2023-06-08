/*
** EPITECH PROJECT, 2023
** lib
** File description:
** functions to open and read a file without stat
*/

#include "../include/my.h"

/*
** EPITECH PROJECT, 2023
** side_library
** File description:
** function to open and store a file content in a truct, with stat authorized
*/

#include "../../include/my.h"

int open_file(file_t file, char *filepath, int size, items_t m)
{
    file->fd = open(filepath, O_RDONLY);

    if (file->fd == -1){
        close(file->fd);
        return my_error("Error: Invalid file name", m);
    }

    file->filepath = my_strdup(filepath);
    file->len = size;
    return 0;
}

int read_file(file_t file, items_t m)
{
    file->text = malloc(sizeof(char) * (file->len + 1));

    if ((file->text) == NULL)
        return my_error("Error: Can't malloc", m);

    if (read(file->fd, file->text, file->len + 1) != file->len)
        return my_error("Error: Can't read the file", m);

    file->text[file->len] = '\0';
    close(file->fd);
    return 0;
}

int init_file_struct(file_t file, char *filepath, int size, items_t m)
{
    file = malloc(sizeof(file_s));

    if (file == NULL)
        return my_error("Error: Can't malloc", m);

    if (open_file(file, filepath, size, m) == 84)
        return 84;

    if (read_file(file, m) == 84)
        return 84;

    m->file = file;
    return 0;
}
