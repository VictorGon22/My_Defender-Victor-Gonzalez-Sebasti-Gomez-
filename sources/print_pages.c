/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void fill_flags(struct_pages *flags)
{
    flags[0].op = 1;
    flags[0].ptr = &print_page_portada;
    flags[1].op = 2;
    flags[1].ptr = &print_page_mainmenu;
    flags[2].op = 3;
    flags[2].ptr = &print_page_settings;
    flags[3].op = 4;
    flags[3].ptr = &print_page_levels;
    flags[4].op = 5;
    flags[4].ptr = &print_page_game;
}

void manage_pages(all_var *all)
{
    int i = 0;

    struct_pages flags[5];
    fill_flags(flags);
    while (i < 5) {
        if (all->var->page == flags[i].op)
            (*(flags[i].ptr))(all);
        i++;
    }
    all->var->prevpage = all->var->page;
}


int is_button_pressed(new_button *button, all_var *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->windows->window);

    if ((mouse.x > button->but.x && mouse.x < (button->but.x + button->size.x))
    && (mouse.y > button->but.y && mouse.y < (button->but.y + button->size.y))) {
        return (1);
    }
    return (0);
}

new_button *create_button(int x, int y, int size_x, int size_y)
{
    new_button *temp = malloc(sizeof(new_button));

    temp->but = (sfVector2i){x, y};
    temp->size = (sfVector2i){size_x, size_y};
    return (temp);
}

void page_portada(all_var *all)
{
    int i = -1;
    new_button *play_button = create_button(600, 650, 670, 270);

    i = is_button_pressed(play_button, all);
    if (all->windows->event.type == sfEvtMouseButtonPressed && i == 1) {
        sfClock_restart(all->clocks->clock_button);
        all->var->page = 2;
    }
}

void scale_images(all_var *all)
{
    sfSprite_scale(all->sprites->soldier_run, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->soldier_u, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->soldier_d_d, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->soldier_d_u, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->portada, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->mainmenu, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->settings, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->shop, (sfVector2f){0.8, 0.7});
    sfSprite_scale(all->sprites->levels, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->tower_1, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_2, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_3, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_4, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->coin, (sfVector2f){0.3, 0.3});
}

void print_page_portada(all_var *all)
{
    page_portada(all);
    sfSprite_setPosition(all->sprites->portada, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->portada, NULL);
    sfRenderWindow_display(all->windows->window);
}

void page_mainmenu(all_var *all)
{
    new_button *back_button = create_button(69, 27, 170, 130);
    new_button *levels_button = create_button(680, 420, 500, 170);
    new_button *play_button = create_button(600, 650, 670, 270);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(back_button, all) == 1) {
            all->var->page = 1;
        } else if (is_button_pressed(levels_button, all) == 1) {
            all->var->page = 4;
        } else if (is_button_pressed(play_button, all) == 1) {
            all->var->page = 5;
        }
        sfClock_restart(all->clocks->clock_button);
    }
}

void print_page_mainmenu(all_var *all)
{
    page_mainmenu(all);
    sfSprite_setPosition(all->sprites->mainmenu, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->mainmenu, NULL);
    sfRenderWindow_display(all->windows->window);
}


void page_settings(all_var *all)
{
    new_button *back_button = create_button(69, 27, 170, 130);
    new_button *music_on = create_button(69, 27, 170, 130);
    new_button *music_off = create_button(69, 27, 170, 130);
    new_button *fps_30 = create_button(69, 27, 170, 130);
    new_button *fps_60 = create_button(69, 27, 170, 130);
    new_button *fps_120 = create_button(69, 27, 170, 130);
    new_button *hd_button = create_button(69, 27, 170, 130);
    new_button *fhd_button = create_button(69, 27, 170, 130);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(back_button, all) == 1) {
            printf("Entra\n");
            all->var->page = 2;
        } else if (is_button_pressed(music_on, all) == 1) {
            all->var->sound_on = 1;
            printf("1\n");
        } else if (is_button_pressed(music_off, all) == 1) {
            all->var->sound_on = 2;
            printf("2\n");
        } else if (is_button_pressed(fps_30, all) == 1) {
            all->var->fps = 30;
            printf("3\n");
        } else if (is_button_pressed(fps_60, all) == 1) {
            all->var->fps = 60;
            printf("3\n");
        } else if (is_button_pressed(fps_120, all) == 1) {
            all->var->fps = 30;
            printf("3\n");
        } else if (is_button_pressed(hd_button, all) == 1) {
            all->var->level = 3;
            printf("3\n");
        } else if (is_button_pressed(fhd_button, all) == 1) {
            all->var->level = 3;
            printf("3\n");
        }
        sfClock_restart(all->clocks->clock_button);
    }
}


void print_page_settings(all_var *all)
{
    sfSprite_setPosition(all->sprites->settings, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->settings, NULL);
    sfRenderWindow_display(all->windows->window);
}

void page_levels(all_var *all)
{
    new_button *back_button = create_button(69, 27, 170, 130);
    new_button *levels1 = create_button(680, 220, 500, 170);
    new_button *levels2 = create_button(680, 420, 500, 170);
    new_button *levels3 = create_button(680, 620, 500, 170);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    printf("ENTRA\n %f", sfTime_asSeconds(all->clocks->time_button));
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(back_button, all) == 1) {
            printf("Entra\n");
            all->var->page = 2;
        } else if (is_button_pressed(levels1, all) == 1) {
            all->var->level = 1;
            printf("1\n");
        } else if (is_button_pressed(levels2, all) == 1) {
            all->var->level = 2;
            printf("2\n");
        } else if (is_button_pressed(levels3, all) == 1) {
            all->var->level = 3;
            printf("3\n");
        }
        sfClock_restart(all->clocks->clock_button);
    }
    printf("0\n");
}

void print_page_levels(all_var *all)
{
    page_levels(all);
    sfSprite_setPosition(all->sprites->levels, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->levels, NULL);
    sfRenderWindow_display(all->windows->window);
}


void change_char (sfIntRect *select_char)
{
    select_char->left += 300;
    if (select_char->left >= 5100)
        select_char->left = 0;
}

void change_money (sfIntRect *select_coin)
{
    select_coin->left += 56;
    if (select_coin->left >= 733)
        select_coin->left = 0;
}

sfVector2f pos_money2(all_var *all)
{
    if (all->var->money <= 999)
        return ((sfVector2f){130, 110});
    else if (all->var->money <= 9999)
        return ((sfVector2f){120, 110});
    else
        return ((sfVector2f){110, 110});
}

sfVector2f pos_money(all_var *all)
{
    if (all->var->money <= 9)
        return ((sfVector2f){170, 110});
    else if (all->var->money <= 99)
        return ((sfVector2f){152, 110});
    else
        return (pos_money2(all));
}

void print_soldier_run(all_var *all, t_info_files *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_run, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_run, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_run);
    sfSprite_setTextureRect(all->sprites->soldier_run,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_run, NULL);
}

void print_soldier_d_u(all_var *all,  t_info_files *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_d_u, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_d_u, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_d_u);
    sfSprite_setTextureRect(all->sprites->soldier_d_u,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_d_u, NULL);
}

void print_soldier_d_d(all_var *all,  t_info_files *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_d_d, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_d_d, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_d_d);
    sfSprite_setTextureRect(all->sprites->soldier_d_d,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_d_d, NULL);
}

void print_soldier_u(all_var *all,  t_info_files *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_u, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_u, tmp->velocity_soldier);
    sfSprite_setTextureRect(all->sprites->soldier_u,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_u, NULL);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_u);
}

void print_tower_in_slot(all_var *all)
{
    sfSprite_setPosition(all->sprites->soldier_u, all->vectors->pos_actual);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_u, NULL);
    
}

void print_shop3(all_var *all)
{
    int i = 0;
    int j = 170;
    int price = 100;

    while (i < 4) {
        sfText_setString(all->texts->text, my_return_time(price));
        sfText_setPosition(all->texts->text, (sfVector2f){200 + j, 170});
        sfSprite_setPosition(all->sprites->coin, (sfVector2f){250 + j, 170});
        sfRenderWindow_drawText(all->windows->window, all->texts->text, NULL);
        sfRenderWindow_drawSprite(all->windows->window, all->sprites->coin, NULL);
        price += 100;
        j += 300;
        i++;
    }
    sfSprite_setPosition(all->sprites->money, all->vectors->pos_money);
    sfSprite_setTextureRect(all->sprites->money,  all->vectors->select_coin);
    all->clocks->time = sfClock_getElapsedTime(all->clocks->clock_coin);
    if (sfTime_asSeconds(all->clocks->time) > 0.2) {
        change_money(&all->vectors->select_coin);
        sfClock_restart(all->clocks->clock_coin);
    }
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->money, NULL);
    
}

void print_shop2(all_var *all)
{
    sfText_setCharacterSize(all->texts->text, 30);
    sfText_setString(all->texts->text2, "Rock tower");
    sfText_setPosition(all->texts->text2, (sfVector2f){350, 100});
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    sfText_setString(all->texts->text2, "Potion tower");
    sfText_setPosition(all->texts->text2, (sfVector2f){640, 100});
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    sfText_setString(all->texts->text2, "Laser tower");
    sfText_setPosition(all->texts->text2, (sfVector2f){950, 100});
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    sfText_setString(all->texts->text2, "Tesla tower");
    sfText_setPosition(all->texts->text2, (sfVector2f){1250, 100});
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    print_shop3(all);
}

void print_char(all_var *all, t_info_files *tmp)
{
    all->clocks->time_char = sfClock_getElapsedTime(all->clocks->clock_char);
    if (sfTime_asSeconds(all->clocks->time_char) > 0.05) {
        change_char(&all->vectors->select_character);
        sfClock_restart(all->clocks->clock_char);
    }
    if (tmp->pos_soldier.x >= 0 && tmp->pos_soldier.x <= 370 ||
    tmp->pos_soldier.x >= 435 && tmp->pos_soldier.x <= 650)  { // RECTE
        tmp->velocity_soldier = (sfVector2f) {3, 0};
        print_soldier_run(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 370 && tmp->pos_soldier.x <= 435
    &&  tmp->pos_soldier.y >= 370) {// UP
        tmp->velocity_soldier = (sfVector2f) {0.6, -3};
        print_soldier_u(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 650 && tmp->pos_soldier.x <= 970)  { // D_D
        tmp->velocity_soldier = (sfVector2f) {2.7, 1.8};
        print_soldier_d_d(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 970 && tmp->pos_soldier.x <= 1150)  { //ST
        tmp->velocity_soldier = (sfVector2f) {3, 0};
        print_soldier_run(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 1150 && tmp->pos_soldier.x <= 1550)  { // D_U
        tmp->velocity_soldier = (sfVector2f) {2.2, -1.6};
        print_soldier_d_u(all, tmp);
    }
}

void print_shop(all_var *all)
{
    sfSprite_setPosition(all->sprites->shop, (sfVector2f){100, -20});
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->shop, NULL);
    sfSprite_setPosition(all->sprites->tower_1, all->vectors->pos_tower_1_shop);
    sfSprite_setPosition(all->sprites->tower_2, all->vectors->pos_tower_2_shop);
    sfSprite_setPosition(all->sprites->tower_3, all->vectors->pos_tower_3_shop);
    sfSprite_setPosition(all->sprites->tower_4, all->vectors->pos_tower_4_shop);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1, NULL);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_2, NULL);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_3, NULL);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_4, NULL);
    sfText_setColor(all->texts->text, sfColor_fromRGB(0, 0, 0));
    sfText_setCharacterSize(all->texts->text, 60);
    sfText_setString(all->texts->text, my_return_time(all->var->money));
    sfText_setPosition(all->texts->text, (pos_money(all)));
    sfRenderWindow_drawText(all->windows->window, all->texts->text, NULL);
    sfText_setCharacterSize(all->texts->text, 40);
    sfText_setString(all->texts->text, "Money");
    sfText_setPosition(all->texts->text, (sfVector2f){120, 70});
    sfRenderWindow_drawText(all->windows->window, all->texts->text, NULL);
    sfText_setColor(all->texts->text, sfColor_fromRGB(255, 255, 255));
    print_shop2(all);
}

void print_page_game(all_var *all)
{   
    // POT VARIAR SEGONS EL NIVELL SERA UN SPRITE O UN ALTRE
    sfSprite_setPosition(all->sprites->background, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->background, NULL);
    
    //SHOP
    print_shop(all);

    if (all->vectors->pos_actual.x >= 0 && all->vectors->pos_actual.x <= 1550)
        sfMusic_play(all->sounds->soldiers_steps);
    else
        sfMusic_pause(all->sounds->soldiers_steps);
    //IMPRESIÓ TORRES 1 A 5

    ///////////// Movment player
    t_info_files *tmp = all->soldiers->next;
    printf("live: %d\n", tmp->live);
    while (tmp->next != NULL) {
        //if (tmp->prev != NULL)
        printf("actual: %d prev:%d %f\n", tmp->live, tmp->prev->live, tmp->prev->pos_soldier.x);
        if (tmp->live == 0 || tmp->prev->pos_soldier.x >= 100) {
            printf("live: %d\n", tmp->live);
            print_char(all, tmp);
        }
        tmp = tmp->next;
    }

    /*print_char(all, all->soldiers->next);
    if (all->soldiers->next->pos_soldier.x >= 100) {
        print_char(all, all->soldiers->next->next);
        printf("%d %d\n", all->soldiers->next->live, all->soldiers->next->next->prev->live);
    }
    if (all->soldiers->next->next->pos_soldier.x >= 100)
        print_char(all, all->soldiers->next->next->next);
    if (all->vectors->pos_actual.x >= 1550)
        all->vectors->pos_actual = (sfVector2f) {0, 700};
    */
    //////////////// IMPRESIO TORRES 6 A 10
    
    
    
    
    
    
    
    sfRenderWindow_display(all->windows->window);




}
