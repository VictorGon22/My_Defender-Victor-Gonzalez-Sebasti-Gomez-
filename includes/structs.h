/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>

    //STRUCT SPRITES
    typedef struct s_sprites_var {
        sfSprite *tower_1;
        sfSprite *tower_2;
        sfSprite *tower_3;
        sfSprite *tower_4;
        sfSprite *tower_1_2;
        sfSprite *tower_2_2;
        sfSprite *tower_3_2;
        sfSprite *tower_4_2;
        sfSprite *upg_tower_1;
        sfSprite *upg_tower_2;
        sfSprite *upg_tower_3;
        sfSprite *upg_tower_4;
        sfSprite *no_upgrades;
        sfSprite *soldier_d_d;
        sfSprite *soldier_d_u;
        sfSprite *soldier_u;
        sfSprite *soldier_run;
        sfSprite *background;
        sfSprite *castle_live;
        sfSprite *coin;
        sfSprite *money;
        sfSprite *levels;
        sfSprite *mainmenu;
        sfSprite *portada;
        sfSprite *settings;
        sfSprite *shop;
        sfSprite *trash;
        sfSprite *game_over;
        sfSprite *soldier_health;
        sfSprite *shine;
        sfSprite *lose;
        sfSprite *win;
        sfSprite *light_button;
        sfSprite *light_play;
        sfSprite *light_small;
    } sprites_var;

    //STRUCT CLOCKS
    typedef struct s_clocks_var {
        sfClock *clock_coin;
        sfClock *clock_char;
        sfClock *clock_button;
        sfClock *clock_button2;
        sfClock *clock_live;
        sfClock *clock_timeplaying;
        sfClock *clock_between_waves;
        sfTime time;
        sfTime time_playing;
        sfTime time_char;
        sfTime time_button;
        sfTime time_button2;
        sfTime time_live;
        sfTime time_between_waves;
    } clocks_var;

    //STRUCT SOUNDS    
    typedef struct s_sound_var {
        sfSound *money;
        sfSound *wrong;
        sfSound *sound_button;
        sfSound *laser;
        sfSound *electric;
        sfSound *poition;
        sfSound *rocks;
        sfMusic *soldiers_steps;
        sfSound *upgrade;
        sfMusic *music_game;
        sfSoundBuffer *buffer; 
    } sound_var;

    //STRUCT WINDOW
    typedef struct s_window_var {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;    
    } window_var;

    //STRUCT VECTORS
    typedef struct s_vectors_var {
        sfVector2f pos_origin;
        sfVector2f pos_tower_1_shop;
        sfVector2f pos_tower_2_shop;
        sfVector2f pos_tower_3_shop;
        sfVector2f pos_tower_4_shop;
        sfVector2f pos_text;
        sfVector2f pos_money;
        sfVector2f pos_character;
        sfVector2f pos_actual;
        sfVector2f velocity_character; 

        sfIntRect select_coin;
        sfIntRect select_character;
        sfIntRect select_live;
        sfIntRect select_soldier_health;

    //POS TORRES MAP 1
        sfVector2f pos_tower_slot1;
        sfVector2f pos_tower_slot2;
        sfVector2f pos_tower_slot3;
        sfVector2f pos_tower_slot4;
        sfVector2f pos_tower_slot5;
        sfVector2f pos_tower_slot6;
        sfVector2f pos_tower_slot7;
        sfVector2f pos_tower_slot8;
        sfVector2f pos_tower_slot9;
        sfVector2f pos_tower_slot10;
        
    } vectors_var;

    //STRUCT TEXTS
    typedef struct s_texts_var {
        sfFont *font;
        sfText *text;
        sfText *text2;
        sfText *textmsg;
    } texts_var;

    //STRUCT VAR
    typedef struct s_var {
        int page;
        int prevpage;
        int sound_on;
        int prev_sound;
        int fps;
        int prev_fps;
        int level;
        int num_lives;
        int enemy_killed;
        int enemy_waves;
        int score;
        int money;
        int tower_type;
        int sound_steps;
    } t_var;

    //STRUCT INFO_TOWERS
    typedef struct s_slots_towers_var {
        struct s_infotowers_var *slot1;
    } slots_var;

    //STRUCT INFO_SOLDIERS
    typedef struct s_info_soldiers {
        int num_soldier;
        int live;
        int damage;
        sfVector2f pos_soldier;
        sfVector2f velocity_soldier;
        sfIntRect select_soldier_health;
        struct s_info_soldiers *prev;
        struct s_info_soldiers *next;
    } t_info_soldiers;

    //STRUCT INFO_TOWERS
    typedef struct s_info_slots {
        int num_slot;
        int show_upgrade;
        int type_tower;
        int level_tower;
        sfVector2f pos_slot;
        struct s_button *upgrade_button;
        struct s_info_slots *prev;
        struct s_info_slots *next;
    } t_info_slots;

    //STRUCT ALL
    typedef struct s_all_var {
        struct s_sound_var *sounds;
        struct s_sprites_var *sprites;
        struct s_vectors_var *vectors;
        struct s_clocks_var *clocks;
        struct s_window_var *windows;
        struct s_texts_var *texts;
        struct s_info_slots *slots;
        struct s_info_soldiers *soldiers;
        struct s_var *var;
    } all_var;

    typedef struct s_button {
        sfVector2i but;
        sfVector2i size;
    } new_button;

    //Function pointers for manage_pages
    typedef struct do_op {
        int op;
        void (*ptr)(all_var *all);
    } struct_pages;

/*
    typedef struct s_var {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfSoundBuffer *buffer;
    sfSoundBuffer *buffer2;
    sfSound *sound_dead;
    sfSound *sound_jump;
    sfSound *sound_touched;
    sfSound *sound_select;
    sfMusic *music_game;
    sfIntRect select_character;
    sfClock *clock;
    sfClock *clock2;
    sfEvent event;
    sfTime time;
    sfSprite *background;
    sfSprite *background2;
    sfSprite *background3;
    sfSprite *textlevels;
    sfSprite *button1;
    sfSprite *button2;
    sfSprite *button3;
    sfSprite *character;
    sfSprite *gameover;
    sfSprite *lives;
    sfSprite *rocket;
    sfSprite *char_jump;
    sfSprite *char_bend;
    sfVector2f pos_errase;
    sfVector2f posbuttons;
    sfVector2f pos_character;
    sfVector2f pos_rocket;
    sfVector2f pos_background;
    sfVector2f pos_background_2;
    sfVector2f pos_background2;
    sfVector2f pos_background2_2;
    sfVector2f pos_background3;
    sfVector2f pos_background3_2;
    sfVector2f velocity_character_down;
    sfVector2f velocity_character_up;
    sfVector2f velocity_background;
    sfVector2f velocity_background2;
    sfVector2f velocity_background3;
    sfVector2f velocity_rocket;
    sfVector2f velocity;
    sfFont *font;
    sfText *text;
    sfText *textmsg;
    sfVector2f pos_textmsg;
    sfVector2f pos_text;
    int counter;
    int hit;
    int level;
    int num_lives;
    int score;
    int dead;
    int jump;
    }t_var;

*/
#endif
