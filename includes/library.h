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
void print_game_over(all_var *all);
void scale_images(all_var *all);
void create_msg (all_var *all);
char *my_return_time(int nb);
sfVector2f save_pos_slot(int num_slot);
void func_fps(all_var *all);
char *my_revstr(char *str);
void func_sound(all_var *all);
void print_upgrade(all_var *all, int num_slot);
void create_soldiers(t_info_soldiers *file);
t_info_soldiers *ini_linked_soldiers(int i);
new_button *create_button(int x, int y, int size_x, int size_y);
t_info_slots *ini_linked_slots(int i);
sfSprite *create_white(void);
void shop_buttons(all_var *all);
sfSprite *create_shine(void);
sfSprite *create_tower_1(void);
sfSprite *create_tower_2(void);
sfSprite *create_tower_3(void);
sfSprite *create_tower_4(void);
sfSprite *create_tower_1_2(void);
sfSprite *create_tower_2_2(void);
sfSprite *create_tower_3_2(void);
sfSprite *create_tower_4_2(void);
sfSprite *create_no_upgrades(void);
sfSprite *create_upg_tower_1(void);
sfSprite *create_upg_tower_2(void);
sfSprite *create_upg_tower_3(void);
sfSprite *create_upg_tower_4(void);
sfSprite *create_soldier_d_d(void);
sfSprite *create_soldier_d_u(void);
sfSprite *create_soldier_u(void);
sfSprite *create_soldier_run(void);
sfSprite *create_soldier_health(void);
sfSprite *create_background(void);
sfSprite *create_castle_live(void);
sfSprite *create_coin(void);
sfSprite *create_money(void);
sfSprite *create_levels(void);
sfSprite *create_mainmenu(void);
sfSprite *create_portada(void);
sfSprite *create_settings(void);
sfSprite *create_shop(void);
sfSprite *create_trash(void);
sfSprite *create_game_over(void);
sfSprite *create_lose(void);
sfSprite *create_win(void);
sfSprite *create_light_button(void);
sfSprite *create_light_play(void);
sfSprite *create_light_small(void);

#endif
