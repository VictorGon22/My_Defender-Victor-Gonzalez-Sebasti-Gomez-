/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"
#include "./../includes/structs.h"

void my_putchar(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int fs_open_file(char const *filepath)
{
    if (open(filepath, O_RDONLY) != -1) {
        return (0);
    }
    else {
        exit (84);
    }
}

int nb_len(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *ext_my_return_time(int nb, char *str, int neg)
{
    int i = 0;

    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i++;
    }
    if (neg == 1) {
        str[i] = '-';
        i++;

    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

char *my_return_time(int nb)
{
    char *str = malloc(sizeof(char) * nb_len(nb) + 1);
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    if (nb == 0)
        return ("0\0");
    return (ext_my_return_time(nb, str, neg));
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *my_revstr(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen2(str) + 1);
    int j = my_strlen2(str);
    int i = 0;

    while (str[i] != '\0')
    {
        dup[i] = str[j];
        i++;
        j--;
    }
    dup[i] = '\0';
    return (dup);
}