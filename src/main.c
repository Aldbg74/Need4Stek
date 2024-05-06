/*
** EPITECH PROJECT, 2024
** B-AIA-200-LYN-2-1-n4s-alexis.drago-beltran
** File description:
** main.c
*/

#include "../include/n4s.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>

static void my_putstr(char *str)
{
    write(1, str, strlen(str));
}

char *set_command(char *str)
{
    char *line = NULL;
    size_t len = 0;

    my_putstr(str);
    getline(&line, &len, stdin);
    return line;
}

int *direction(char *str)
{
    int *array = malloc(8 * sizeof(int));
    int cmp = 0;

    for (int i = 3; i != 6; i++)
        cmp = cmp + str[i];
    array[0] = cmp / 4;
    cmp = 0;
    for (int i = 7; i != 10; i++)
        cmp = cmp + str[i];
    array[1] = cmp / 4;
    cmp = 0;
    for (int i = 11; i != 14; i++)
        cmp = cmp + str[i];
    array[2] = cmp / 4;
    cmp = 0;
    for (int i = 15; i != 18; i++)
        cmp = cmp + str[i];
    array[3] = cmp / 4;
    cmp = 0;
    for (int i = 19; i != 22; i++)
        cmp = cmp + str[i];
    array[4] = cmp / 4;
    cmp = 0;
    for (int i = 23; i != 26; i++)
        cmp = cmp + str[i];
    array[5] = cmp / 4;
    cmp = 0;
    for (int i = 27; i != 30; i++)
        cmp = cmp + str[i];
    array[6] = cmp / 4;
    cmp = 0;
    for (int i = 31; i != 34; i++)
        cmp = cmp + str[i];
    array[7] = cmp / 4;
    return array;
}

void turn2(int temp, char *data)
{
    if (temp > 0)
        dprintf(1, "WHEELS_DIR:0.3\n");
    if (temp < 0)
        dprintf(1, "WHEELS_DIR:-0.3\n");
}

void turn(int *data, int fd)
{
    int temp = 0;

    if (data[0] > data[7])
        temp++;
    else
        temp--;
    if (data[1] > data[6])
        temp++;
    else
        temp--;
    if (data[2] > data[5])
        temp++;
    else
        temp--;
    if (data[3] > data[4])
        temp++;
    else
        temp--;
    turn2(temp, data);
}

int main(void)
{
    int *data;
    int fd = open("test.txt", O_WRONLY);

    set_command("start_simulation\n");
    set_command("car_forward:0.3\n");
    while (1) {
        dprintf(fd, "Lidar = %s\n", set_command("GET_INFO_LIDAR\n"));
        data = direction(set_command("GET_INFO_LIDAR\n"));
        if (data[3] < 100)
            turn(data, fd);
        free(data);
    }
    set_command("stop_simulation\n");
    close(fd);
    return 0;
}
