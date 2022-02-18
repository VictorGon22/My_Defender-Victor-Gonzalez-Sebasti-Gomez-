/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void ini_struct_sprites(all_var  *all)
{
    all->sprites->tower_1 = create_tower_1();
    all->sprites->tower_2 = create_tower_2();
    all->sprites->tower_3 = create_tower_3();
    all->sprites->tower_4 = create_tower_4();
    all->sprites->upg_tower_1 = create_upg_tower_1();
    all->sprites->upg_tower_2 = create_upg_tower_2();
    all->sprites->upg_tower_3 = create_upg_tower_3();
    all->sprites->upg_tower_4 = create_upg_tower_4();
    all->sprites->no_upgrades = create_no_upgrades();
    all->sprites->soldier_d_d = create_soldier_d_d();
    all->sprites->soldier_d_u = create_soldier_d_u();
    all->sprites->soldier_u = create_soldier_u();
    all->sprites->soldier_run = create_soldier_run();
    all->sprites->soldier_health = create_soldier_health();   
    all->sprites->background = create_background();
    all->sprites->castle_live = create_castle_live();
    all->sprites->coin = create_coin();
    all->sprites->money = create_money();
    all->sprites->mainmenu = create_mainmenu();
    all->sprites->portada = create_portada();
    all->sprites->settings = create_settings();
    all->sprites->levels = create_levels();
    all->sprites->shop = create_shop(); 
    all->sprites->tower_1_2 = create_tower_1_2();
    all->sprites->tower_2_2 = create_tower_2_2();
    all->sprites->tower_3_2 = create_tower_3_2();
    all->sprites->tower_4_2 = create_tower_4_2();
    all->sprites->trash = create_trash();
    all->sprites->shine = create_shine();
    all->sprites->game_over = create_game_over();
    all->sprites->lose = create_lose();
    all->sprites->win = create_win();
    all->sprites->light_button = create_light_button();
    all->sprites->light_play = create_light_play();
    all->sprites->light_small = create_light_small();
}

all_var *init_var_all(void)
{
    all_var *all = malloc(sizeof(all_var));
    all->sounds = malloc(sizeof(sound_var));
    all->vectors = malloc(sizeof(vectors_var));
    all->clocks = malloc(sizeof(clocks_var));
    all->sprites = malloc(sizeof(sprites_var));
    all->windows = malloc(sizeof(window_var));
    all->texts = malloc(sizeof(texts_var));
    all->slots = malloc(sizeof(t_info_slots));
    all->soldiers = malloc(sizeof(t_info_soldiers));
    all->var = malloc(sizeof(t_var));
    if (all->sounds == NULL ||  all->vectors == NULL || all->clocks == NULL || all->sprites == NULL || all->windows == NULL || all->var == NULL)
        printf("ERROOOOR\n");
    return all;
}

void analayse_events(all_var *all, int page)
{
    int hit = 0;

    while (sfRenderWindow_pollEvent(all->windows->window, &all->windows->event)) {
        if (all->windows->event.type == sfEvtClosed) {
            sfRenderWindow_close(all->windows-> window);
        }
    }
}

void func_sound(all_var *all)
{
    if (all->var->sound_on == 0)
    {
        all->var->prev_sound = 0;
        sfMusic_pause(all->sounds->music_game);
    }
    else if (all->var->sound_on == 1 && all->var->prev_sound == 0) {
        all->var->prev_sound = 1;
        sfMusic_play(all->sounds->music_game);
    }
}

void func_fps(all_var *all)
{
    if (all->var->fps != all->var->prev_fps)
    {
        all->var->prev_fps = all->var->fps;
        sfRenderWindow_setFramerateLimit(all->windows->window, all->var->fps);
    }
    switch (all->var->fps)
    {
        case 30:
            sfSprite_setPosition(all->sprites->tower_1, (sfVector2f){960, 440});
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1, NULL);
            break;
        case 60:
            sfSprite_setPosition(all->sprites->tower_1, (sfVector2f){1260, 440});
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1, NULL);
            break;
        case 120:
            sfSprite_setPosition(all->sprites->tower_1, (sfVector2f){1530, 440});
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1, NULL);
            break;
    }
}

sfRenderWindow *my_window(all_var *all)
{
    srand(time(NULL));
    all->var->score = 0;
    all->var->page = 3;
    all->var->sound_on = 1;
    all->var->enemy_killed = 0;
    all->var->prev_sound = 1;
    all->var->prev_fps = 60;
    all->var->fps = 60;
    sfMusic_play(all->sounds->music_game);
    scale_images(all);
    while (sfRenderWindow_isOpen(all->windows->window)) {
        sfRenderWindow_clear(all->windows->window, sfBlack);
        sfRenderWindow_setFramerateLimit(all->windows->window, 30);
        analayse_events(all, 0);
        manage_pages(all);
    }
    sfMusic_destroy(all->sounds->music_game);
    sfMusic_destroy(all->sounds->soldiers_steps);
}
///////////////////////////////////////////////////////SOLDIERS
t_info_soldiers *init_struc_soldiers(void)
{
    t_info_soldiers *res = malloc(sizeof(t_info_soldiers));
    res->next = NULL;
    return res;
}

t_info_soldiers *ini_linked_soldiers(int i)
{
    t_info_soldiers *file = malloc(sizeof(t_info_soldiers) * 1);

    if (file == NULL)
        perror("error\n");
    file->prev = NULL;
    file->num_soldier = i;
    file->live = 0;
    file->damage = 0;
    file->select_soldier_health = (sfIntRect) {0, 0, 450, 50};
    file->pos_soldier = (sfVector2f) {0, 700};
    file->velocity_soldier;
    file->next = NULL;
    return file;
}

void create_soldiers(t_info_soldiers *file)
{
    t_info_soldiers *tmp = file;
    t_info_soldiers *tmp2 = file;
    int i = 0;
    int j = 0;
    while (tmp->next != NULL) {
        j++;
        tmp = tmp->next;
    }
    tmp->next = ini_linked_soldiers(j);
    while (i < j - 1) {
        tmp2 = tmp2->next;
        i++;
    }
    if (j == 0)
        tmp->prev = NULL;
    else {
        tmp->prev = tmp2;
    }
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////TOWERS
sfVector2f save_pos_slot(int num_slot)
{
    switch (num_slot)
    {
        case 1:
            return ((sfVector2f) {305, 500});
        case 2:
            return ((sfVector2f) {420, 235});
        case 3:
            return ((sfVector2f) {840, 265});
        case 4:
            return ((sfVector2f) {1080, 403});
        case 5:
            return ((sfVector2f) {1380, 238});
        case 6:
            return ((sfVector2f) {350, 670});
        case 7:
            return ((sfVector2f) {576, 375});
        case 8:
            return ((sfVector2f) {840, 480});
        case 9:
            return ((sfVector2f) {1325, 515});
        case 10:
            return ((sfVector2f) {1565, 350});
    }
}

t_info_slots *init_struc_slots(void)
{
    t_info_slots *res = malloc(sizeof(t_info_slots));
    res->next = NULL;
    return res;
}

t_info_slots *ini_linked_slots(int i)
{
    t_info_slots *file = malloc(sizeof(t_info_slots) * 1);


    if (file == NULL)
        perror("error\n");
    file->prev = NULL;
    file->show_upgrade = 0;
    file->num_slot = i;
    file->type_tower = 0;
    file->level_tower = 1;
    file->pos_slot = save_pos_slot(i);
    file->upgrade_button = create_button(file->pos_slot.x, file->pos_slot.y, 140, 90);
    file->next = NULL;
    return file;
}

void create_slots(t_info_slots *file)
{
    t_info_slots *tmp = file;
    int i = 0;
    int j = 0;

    while (tmp->next != NULL) {
        j++;
        tmp = tmp->next;
    }
    tmp->next = ini_linked_slots(j);
}

//////////////////////////////////////////////////////////////
void ini_struc_var(all_var *all)
{
    all->var->enemy_waves = 1;
    all->var->num_lives = 5;
    all->var->money = 1000;
    all->var->score = 0;
    all->var->page = 2;
    all->var->sound_on = 1;
    all->var->enemy_killed = 0;
    all->var->prev_sound = 1;
    all->var->prev_fps = 60;
    all->var->fps = 60;
    all->var->level = 0;
    all->var->sound_steps = 0;
}

void my_defender(void)
{
    int i = 0;
    all_var *all = init_var_all();

   //CREATE LINKED SOLDIERS NOW VALUES == O
    all->soldiers = init_struc_soldiers();
    while (i <= 10) {
        create_soldiers(all->soldiers);
        i++;
    }
    //////////////////////////////////
    i = 0;
    all->slots = init_struc_slots();
    while (i <= 11) {
        create_slots(all->slots);
        i++;
    }
    all->var->level = 0;
    ini_struc_var(all);
    sfVideoMode video_mode;
    sfRenderWindow *window;
    all->windows->video_mode = (sfVideoMode){1920, 1080, 64};
    all->windows->window = sfRenderWindow_create(all->windows->video_mode,
    "My-Defender_GAME", sfDefaultStyle, NULL);
    create_sounds(all);
    create_clocks(all);
    create_positions(all);
    ini_struct_sprites(all);
    create_msg(all);
    my_window(all);
    sfRenderWindow_destroy(all->windows->window);
}

int main(int argc, char **argv)
{
    char *buffer = malloc(sizeof(char) * 250);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        //read(open("README.txt", O_RDONLY), buffer, 250);
        //my_putchar(buffer);
    }
    else if (argc == 1 )
        my_defender();
    else
        exit (84);
    free(buffer);
    return 0;
}