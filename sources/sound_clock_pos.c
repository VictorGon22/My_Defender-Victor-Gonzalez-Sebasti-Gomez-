/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void create_sounds(all_var *all)
{
    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/electric.wav");
    all->sounds->electric = sfSound_create();
    sfSound_setBuffer(all->sounds->electric, all->sounds->buffer);

    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/laser.wav");
    all->sounds->laser = sfSound_create();
    sfSound_setBuffer(all->sounds->laser, all->sounds->buffer);

    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/poition.wav");
    all->sounds->poition = sfSound_create();
    sfSound_setBuffer(all->sounds->poition, all->sounds->buffer);

    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/rocks.wav");
    all->sounds->rocks = sfSound_create();
    sfSound_setBuffer(all->sounds->rocks, all->sounds->buffer);


    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/sound_button.wav");
    all->sounds->laser = sfSound_create();
    sfSound_setBuffer(all->sounds->laser, all->sounds->buffer);

    all->sounds->buffer = sfSoundBuffer_createFromFile("./sounds/upgrade.wav");
    all->sounds->electric = sfSound_create();
    sfSound_setBuffer(all->sounds->electric, all->sounds->buffer);

    all->sounds->music_game = sfMusic_createFromFile("./sounds/game_music.wav");
    sfMusic_setLoop(all->sounds->music_game, sfTrue);

    all->sounds->soldiers_steps = sfMusic_createFromFile("./sounds/soldierssteps.wav");
    sfMusic_setLoop(all->sounds->soldiers_steps, sfTrue);
}

void create_clocks(all_var *all)
{
    all->clocks->clock_coin = sfClock_create();
    all->clocks->clock_char = sfClock_create();
    all->clocks->clock_button = sfClock_create();
    all->clocks->clock_button2 = sfClock_create();
}

void create_msg (all_var *all)
{
    all->texts->font = sfFont_createFromFile("./fonts/Ground_Castle.otf");
    all->texts->text = sfText_create();
    sfText_setFont(all->texts->text, all->texts->font);
    sfText_setCharacterSize(all->texts->text, 30);
    all->texts->font = sfFont_createFromFile("./fonts/arial.ttf");
    all->texts->text2 = sfText_create();
    sfText_setFont(all->texts->text2, all->texts->font);
    sfText_setCharacterSize(all->texts->text2, 30);
}


void create_positions(all_var *all)
{
    all->vectors->pos_origin = (sfVector2f) {0, 0};
    all->vectors->pos_tower_1_shop = (sfVector2f) {500, 60};
    all->vectors->pos_tower_2_shop = (sfVector2f) {800, 60};
    all->vectors->pos_tower_3_shop = (sfVector2f) {1100, 60};
    all->vectors->pos_tower_4_shop = (sfVector2f) {1400, 60};

    //afegirlo en una estructura 
    all->vectors->pos_tower_slot1 = (sfVector2f) {500, 60};
    all->vectors->pos_tower_slot2 = (sfVector2f) {600, 60};
    all->vectors->pos_tower_slot3 = (sfVector2f) {700, 60};
    all->vectors->pos_tower_slot4 = (sfVector2f) {800, 60};
    all->vectors->pos_tower_slot5 = (sfVector2f) {900, 60};
    all->vectors->pos_tower_slot6 = (sfVector2f) {1000, 60};
    all->vectors->pos_tower_slot7 = (sfVector2f) {1100, 60};
    all->vectors->pos_tower_slot8 = (sfVector2f) {1200, 60};
    all->vectors->pos_tower_slot9 = (sfVector2f) {1300, 60};
    all->vectors->pos_tower_slot10 = (sfVector2f) {1400, 60};

    all->vectors->pos_text = (sfVector2f) {300, 230};
    all->vectors->pos_money = (sfVector2f) {200, 180};
    all->vectors->select_coin = (sfIntRect) {0, 0, 56, 57};
    all->vectors->select_character = (sfIntRect) {0, 0, 300, 240};
    all->vectors->pos_character = (sfVector2f) {0, 700};
    all->vectors->pos_actual = (sfVector2f) {0, 700};
    all->vectors->velocity_character = (sfVector2f) {5, 0};
}