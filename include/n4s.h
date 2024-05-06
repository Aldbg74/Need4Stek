/*
** EPITECH PROJECT, 2024
** B-AIA-200-LYN-2-1-n4s-alexis.drago-beltran
** File description:
** n4s.h
*/

#ifndef N4S_H_
    #define N4S_H_

int start_car(int arc, char **arv);
void turn(int *data, int fd);
int speed_gestion(int val);
int *direction(char *str);
char *set_command(char *str);
char **my_str_to_word_array(char const *str);

#endif /* !N4S_H_ */
