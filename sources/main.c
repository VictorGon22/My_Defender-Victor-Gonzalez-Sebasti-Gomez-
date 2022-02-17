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
    all->sprites->soldier_d_d = create_soldier_d_d();
    all->sprites->soldier_d_u = create_soldier_d_u();
    all->sprites->soldier_u = create_soldier_u();
    all->sprites->soldier_run = create_soldier_run();
    all->sprites->background = create_background();
    all->sprites->castle_live = create_castle_live();
    all->sprites->coin = create_coin();
    all->sprites->money = create_money();
    all->sprites->mainmenu = create_mainmenu();
    all->sprites->portada = create_portada();
    all->sprites->settings = create_settings();
    all->sprites->levels = create_levels();
    all->sprites->shop = create_shop(); 
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
    all->slots = malloc(sizeof(slots_var));
    all->soldiers = malloc(sizeof(t_info_files));
    all->var = malloc(sizeof(t_var));
    if (all->sounds == NULL ||  all->vectors == NULL || all->clocks == NULL || all->sprites == NULL || all->windows == NULL || all->var == NULL)
        printf("ERROOOOR\n");
    return all;
}

void ini_slots_towers(all_var *all) 
{
    all->slots->slot1 = malloc(sizeof(towers_info_var));
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

sfRenderWindow *my_window(all_var *all)
{
    srand(time(NULL));
    all->var->score = 0;
    all->var->page = 5;
    
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

t_info_files *init_file(void)
{
    t_info_files *res = malloc(sizeof(t_info_files));
    res->next = NULL;
    return res;
}

t_info_files *ini_linked_envp(int i)
{
    t_info_files *file = malloc(sizeof(t_info_files) * 1);

    if (file == NULL)
        perror("error\n");
    file->prev = NULL;
    file->live = i;
    file->pos_soldier = (sfVector2f) {0, 700};
    file->velocity_soldier;
    file->next = NULL;
    return file;
}

void create_new(t_info_files *file)
{
    t_info_files *tmp = file;
    t_info_files *tmp2 = file;
    int i = 0;
    int j = 0;
    while (tmp->next != NULL) {
        j++;
        tmp = tmp->next;
    }
    tmp->next = ini_linked_envp(j);
    while (i < j - 1) {
        tmp2 = tmp2->next;
        i++;
    }
    if (j == 0)
        tmp->prev = NULL;
    else {
        tmp->prev = tmp2;
        printf("%d\n", tmp->prev->live);
    }
    
}

void my_defender(void)
{
    int i = 0;
    all_var *all = init_var_all();

   //CREATE LINKED SOLDIERS NOW VALUES == O
    all->soldiers = init_file();
    while (i < 10) {
        create_new(all->soldiers);
        i++;
    }
    //////////////////////////////////
    sfVideoMode video_mode;
    sfRenderWindow *window;
    all->windows->video_mode = (sfVideoMode){1920, 1080, 64};
    all->windows->window = sfRenderWindow_create(all->windows->video_mode,
    "My-Defender_GAME", sfDefaultStyle, NULL);
    create_sounds(all);
    create_clocks(all);
    create_positions(all);
    ini_struct_sprites(all);
    //ini_var_struct(&var);
    create_msg(all);
    //sfSprite_setPosition(var.textlevels, var.posbuttons);
    //sfSprite_scale(var.lives, (sfVector2f){0.1, 0.1});
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