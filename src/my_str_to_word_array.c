/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-elias.pujol-hering
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/n4s.h"

int charact(char letter)
{
    if (letter == ' ') {
        return 1;
    } else {
        return 0;
    }
}

void condition(char const *str, char **words)
{
    int i = 0;
    int x = 0;
    int y = 0;

    words[y] = malloc(sizeof(char) * (strlen(str) + 1));
    while (str[i] != '\0') {
        if (charact(str[i]) == 1) {
            y++;
            words[y] = malloc(sizeof(char) * (strlen(str) + 1));
            i++;
            x = 0;
        }
        if (charact(str[i]) == 0) {
            words[y][x] = str[i];
            x++;
            i++;
        }
    }
    y++;
    words[y] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    int word_count = strlen(str);
    char **words = malloc(sizeof(char *) * (word_count));

    condition(str, words);
    return (words);
}
