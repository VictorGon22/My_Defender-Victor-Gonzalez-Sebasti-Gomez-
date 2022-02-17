/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"

void create_sounds(all_var *all);
void create_clocks(all_var *all);
void create_positions(all_var *all);
void manage_pages(all_var *all);
void print_page_portada(all_var *all);
void print_page_mainmenu(all_var *all);
void print_page_settings(all_var *all);
void print_page_levels(all_var *all);
void print_page_game(all_var *all);
void scale_images(all_var *all);
void create_msg (all_var *all);
char *my_return_time(int nb);

char *my_revstr(char *str);

sfSprite *create_white(void);

sfSprite *create_tower_1(void);
sfSprite *create_tower_2(void);
sfSprite *create_tower_3(void);
sfSprite *create_tower_4(void);
sfSprite *create_tower_1_2(void);
sfSprite *create_tower_2_2(void);
sfSprite *create_tower_3_2(void);
sfSprite *create_tower_4_2(void);
sfSprite *create_upg_tower_1(void);
sfSprite *create_upg_tower_2(void);
sfSprite *create_upg_tower_3(void);
sfSprite *create_upg_tower_4(void);
sfSprite *create_soldier_d_d(void);
sfSprite *create_soldier_d_u(void);
sfSprite *create_soldier_u(void);
sfSprite *create_soldier_run(void);
sfSprite *create_background(void);
sfSprite *create_castle_live(void);
sfSprite *create_coin(void);
sfSprite *create_money(void);
sfSprite *create_levels(void);
sfSprite *create_mainmenu(void);
sfSprite *create_portada(void);
sfSprite *create_settings(void);
sfSprite *create_shop(void);


#endif
