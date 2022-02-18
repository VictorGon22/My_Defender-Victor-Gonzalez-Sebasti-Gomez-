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
    flags[5].op = 6;
    flags[5].ptr = &print_game_over;
}

void manage_pages(all_var *all)
{
    int i = 0;

    struct_pages flags[6];
    fill_flags(flags);
    while (i < 6) {
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
    sfSprite_scale(all->sprites->soldier_health, (sfVector2f){0.2, 0.2});
    sfSprite_scale(all->sprites->portada, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->mainmenu, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->settings, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->shop, (sfVector2f){0.8, 0.7});
    sfSprite_scale(all->sprites->levels, (sfVector2f){0.98, 0.98});
    sfSprite_scale(all->sprites->tower_1, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_2, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_3, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_4, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->no_upgrades, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->upg_tower_1, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->upg_tower_2, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->upg_tower_3, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->upg_tower_4, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->tower_1_2, (sfVector2f){0.45, 0.45});
    sfSprite_scale(all->sprites->tower_2_2, (sfVector2f){0.45, 0.45});
    sfSprite_scale(all->sprites->tower_3_2, (sfVector2f){0.45, 0.45});
    sfSprite_scale(all->sprites->tower_4_2, (sfVector2f){0.45, 0.45});
    sfSprite_scale(all->sprites->coin, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->castle_live, (sfVector2f){2, 2});
    sfSprite_scale(all->sprites->trash, (sfVector2f){0.3, 0.3});
    sfSprite_scale(all->sprites->shine, (sfVector2f){0.5, 0.5});
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
    new_button *settings_button = create_button(1645, 27, 170, 130);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(back_button, all) == 1) {
            all->var->page = 1;
        } else if (is_button_pressed(levels_button, all) == 1) {
            all->var->page = 4;
        } else if (is_button_pressed(play_button, all) == 1) {
            if (all->var->level != 0) {
                all->var->page = 5;
                sfClock_restart(all->clocks->clock_timeplaying);
            }
            else
                all->var->page = 4;
        } else if (is_button_pressed(settings_button, all) == 1) {
            all->var->page = 3;
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
    new_button *music_off = create_button(920, 150, 170, 130);
    new_button *music_on = create_button(1220, 150, 170, 130);
    new_button *fps_30 = create_button(920, 460, 170, 130);
    new_button *fps_60 = create_button(1220, 460, 170, 130);
    new_button *fps_120 = create_button(1500, 460, 170, 130);
    new_button *hd_button = create_button(930, 770, 170, 130);
    new_button *fhd_button = create_button(1220, 770, 170, 130);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 0.4) {
        if (is_button_pressed(back_button, all) == 1) {
            all->var->page = 2;
        } else if (is_button_pressed(music_off, all) == 1) {
            all->var->sound_on = 0;
        } else if (is_button_pressed(music_on, all) == 1) {
            all->var->sound_on = 1;
        } else if (is_button_pressed(fps_30, all) == 1) {
            all->var->fps = 30;
        } else if (is_button_pressed(fps_60, all) == 1) {
            all->var->fps = 60;
        } else if (is_button_pressed(fps_120, all) == 1) {
            all->var->fps = 120;
        } else if (is_button_pressed(hd_button, all) == 1) {
            all->var->level = 3;
        } else if (is_button_pressed(fhd_button, all) == 1) {
            all->var->level = 3;
        }
        sfClock_restart(all->clocks->clock_button);
    }
}


void print_page_settings(all_var *all)
{
    page_settings(all);
    sfSprite_setPosition(all->sprites->settings, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->settings, NULL);
    func_sound(all);
    func_fps(all);
    sfRenderWindow_display(all->windows->window);
}

void page_levels(all_var *all)
{
    new_button *back_button = create_button(69, 27, 170, 130);
    new_button *levels1 = create_button(690, 200, 500, 170);
    new_button *levels2 = create_button(690, 460, 500, 170);
    new_button *levels3 = create_button(690, 720, 500, 170);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(back_button, all) == 1) {
            all->var->page = 2;
        } else if (is_button_pressed(levels1, all) == 1) {
            all->var->level = 1;
            all->var->page = 2;
        } else if (is_button_pressed(levels2, all) == 1) {
            all->var->level = 2;
            all->var->page = 2;
        } else if (is_button_pressed(levels3, all) == 1) {
            all->var->level = 3;
            all->var->page = 2;
        }
        sfClock_restart(all->clocks->clock_button);
    }
}

void print_page_levels(all_var *all)
{
    page_levels(all);
    sfSprite_setPosition(all->sprites->levels, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->levels, NULL);
    sfRenderWindow_display(all->windows->window);
}

void change_char_health (sfIntRect *select_char)
{
    select_char->top += 50;
    if (select_char->top >= 450)
        select_char->top = 0;
}

void change_char (sfIntRect *select_char)
{
    select_char->left += 300;
    if (select_char->left >= 5100)
        select_char->left = 0;
}

void change_live (sfIntRect *select_live)
{
    select_live->top += 30;
    if (select_live->top >= 150)
        select_live->top = 10;
}

void change_money (sfIntRect *select_coin)
{
    select_coin->left += 57.3846;
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

void print_soldier_health(all_var *all, t_info_soldiers *tmp)
{
    sfVector2f pos = tmp->pos_soldier;
    pos.x += 40;
    sfSprite_setPosition(all->sprites->soldier_health, pos);
    if (tmp->damage >= 25) {
        change_char_health(&tmp->select_soldier_health);
        tmp->damage = 0;
        tmp->live -= 25;
    }
    sfSprite_setTextureRect(all->sprites->soldier_health,  tmp->select_soldier_health);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_health, NULL);
}

void print_soldier_run(all_var *all, t_info_soldiers *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_run, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_run, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_run);
    sfSprite_setTextureRect(all->sprites->soldier_run,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_run, NULL);
    print_soldier_health(all, tmp);
}

void print_soldier_d_u(all_var *all,  t_info_soldiers *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_d_u, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_d_u, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_d_u);
    sfSprite_setTextureRect(all->sprites->soldier_d_u,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_d_u, NULL);
    print_soldier_health(all, tmp);
}

void print_soldier_d_d(all_var *all,  t_info_soldiers *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_d_d, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_d_d, tmp->velocity_soldier);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_d_d);
    sfSprite_setTextureRect(all->sprites->soldier_d_d,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_d_d, NULL);
    print_soldier_health(all, tmp);
}

void print_soldier_u(all_var *all,  t_info_soldiers *tmp)
{
    sfSprite_setPosition(all->sprites->soldier_u, tmp->pos_soldier);
    sfSprite_move(all->sprites->soldier_u, tmp->velocity_soldier);
    sfSprite_setTextureRect(all->sprites->soldier_u,  all->vectors->select_character);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->soldier_u, NULL);
    tmp->pos_soldier = sfSprite_getPosition(all->sprites->soldier_u);
    print_soldier_health(all, tmp);
}

void print_tower_in_slot(all_var *all, t_info_slots *tmp_slots)
{
    switch (tmp_slots->type_tower) {
        case 1:
            sfSprite_setPosition(all->sprites->tower_1_2, tmp_slots->pos_slot);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1_2, NULL);
            break;
        case 2:
            sfSprite_setPosition(all->sprites->tower_2_2, tmp_slots->pos_slot);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_2_2, NULL);
            break;

        case 3:
            sfSprite_setPosition(all->sprites->tower_3_2, tmp_slots->pos_slot);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_3_2, NULL);
            break;
        case 4:
            sfSprite_setPosition(all->sprites->tower_4_2, tmp_slots->pos_slot);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_4_2, NULL);
            break;
    }
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
    sfText_setCharacterSize(all->texts->text2, 30);
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

void print_castle_live(all_var *all)
{
    sfSprite_setPosition(all->sprites->castle_live, (sfVector2f) {1350, 900});
    sfSprite_setTextureRect(all->sprites->castle_live,  all->vectors->select_live);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->castle_live, NULL);

}

void print_char(all_var *all, t_info_soldiers *tmp)
{
    all->clocks->time_char = sfClock_getElapsedTime(all->clocks->clock_char);
    if (sfTime_asSeconds(all->clocks->time_char) > 0.05) {
        change_char(&all->vectors->select_character);
        sfClock_restart(all->clocks->clock_char);
    }
    if (tmp->pos_soldier.x >= 0 && tmp->pos_soldier.x <= 370 ||
    tmp->pos_soldier.x >= 435 && tmp->pos_soldier.x <= 650)  { // RECTE
        tmp->velocity_soldier = (sfVector2f) {3 + (all->var->level * 2), 0};
        print_soldier_run(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 370 && tmp->pos_soldier.x <= 435) {// UP
        tmp->velocity_soldier = (sfVector2f) {0.6 + (all->var->level * 0.20), -3 - all->var->level};
        print_soldier_u(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 650 && tmp->pos_soldier.x <= 970)  { // D_D
        tmp->velocity_soldier = (sfVector2f) {2.7 + (all->var->level * 1.5) , 1.8 + all->var->level};
        print_soldier_d_d(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 970 && tmp->pos_soldier.x <= 1150)  { //ST
        tmp->velocity_soldier = (sfVector2f) {3 + (all->var->level * 2), 0};
        tmp->damage = 25;////////////////////7PROVA PER FERIR-LOS
        print_soldier_run(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 1150 && tmp->pos_soldier.x <= 1500)  { // D_U
        tmp->velocity_soldier = (sfVector2f) {2.2 + all->var->level, -1.6 - (all->var->level * 0.7)};
        print_soldier_d_u(all, tmp);
    }
    else if (tmp->pos_soldier.x >= 1500 && tmp->pos_soldier.x <= 1551) {
        if (tmp->live > 0) {
            change_live(&all->vectors->select_live);
            tmp->live = 0;
        }
        all->var->num_lives--;
        if (all->var->num_lives == 0)
            all->var->page = 6;
    }
    if (tmp->live == 0 & tmp->pos_soldier.x < 1500)
        all->var->enemy_killed++;
}

void print_shop(all_var *all)
{
    sfSprite_setPosition(all->sprites->shop, (sfVector2f){100, -20});
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->shop, NULL);
    shop_buttons(all);
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

void show_upgrade(t_info_slots *tmp_slots)
{
    if (tmp_slots->show_upgrade == 0)
        tmp_slots->show_upgrade = 1;
    else
        tmp_slots->show_upgrade = 0;
}

void write_tower_in_slot(all_var *all, int num_slot, int type_tower) // Crear aqui els butons per millorar
{
    t_info_slots *tmp_slots = all->slots->next;
    
    while (tmp_slots->next != NULL) {
        if (tmp_slots->num_slot == num_slot) {
            if (tmp_slots->type_tower != 0)
               show_upgrade(tmp_slots);
            if (tmp_slots->type_tower == 0 
            && all->var->money >= all->var->tower_type * 100) {
                tmp_slots->type_tower = type_tower;
                sfSound_play(all->sounds->money);
                all->var->money -= all->var->tower_type * 100;
                all->var->tower_type = 0;
            }
            else if (tmp_slots->type_tower == 0 
            && all->var->money < all->var->tower_type * 100) {
                sfSound_play(all->sounds->wrong);
            }
        }
        tmp_slots = tmp_slots->next;
    }
}

void print_tower_in_mouse(all_var *all)
{
    sfVector2i mouse_posi = sfMouse_getPositionRenderWindow(all->windows->window);
    sfVector2f mouse_pos;
    mouse_pos.x = (float)mouse_posi.x - 75;
    mouse_pos.y = (float)mouse_posi.y - 75;
    if (all->var->tower_type != 0) {
        switch (all->var->tower_type) {
            case 1:
                sfSprite_setPosition(all->sprites->tower_1_2, mouse_pos);
                sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_1_2, NULL);
                break;
            case 2:
                sfSprite_setPosition(all->sprites->tower_2_2, mouse_pos);
                sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_2_2, NULL);
                break;
            case 3:
                sfSprite_setPosition(all->sprites->tower_3_2, mouse_pos);
                sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_3_2, NULL);
                break;
            case 4:
                sfSprite_setPosition(all->sprites->tower_4_2, mouse_pos);
                sfRenderWindow_drawSprite(all->windows->window, all->sprites->tower_4_2, NULL);
                break;
            default:
                all->var->tower_type = 0;
                break;
        }
    }
}

int get_tower_type(all_var *all, int num_slot)
{
    t_info_slots *tmp_slots = all->slots
    ;

    while (tmp_slots->next != NULL) {
        if (tmp_slots->num_slot == num_slot)
            return (tmp_slots->type_tower);
        tmp_slots = tmp_slots->next;
    }
    return (0);
}

void upgrade_buttons(all_var *all, int num_slot)
{
    t_info_slots *temp = all->slots->next;

    while (temp->num_slot != num_slot && temp->next != NULL)
        temp = temp->next;
    all->clocks->time_button = 
    sfClock_getElapsedTime(all->clocks->clock_button);
    printf("%f\n", sfTime_asSeconds(all->clocks->time_button));
    if (all->windows->event.type == sfEvtMouseButtonPressed && 
    sfTime_asSeconds(all->clocks->time_button) > 0.1
    && is_button_pressed(temp->upgrade_button, all) == 1) {
        temp->level_tower += 1;
        sfSound_play(all->sounds->upgrade);
        sfClock_restart(all->clocks->clock_button);
    }
}

/*
void print_upgrade2(all_var *all, int num_slot, sfVector2f pos, sfSprites *tower_upgrade)
{
    sfSprite_setPosition(tower_upgrade, pos);
    sfRenderWindow_drawSprite(all->windows->window, tower_upgrade, NULL);
    upgrade_buttons(all, num_slot);
}

*/


void print_upgrade(all_var *all, int num_slot)
{
    sfVector2f pos = save_pos_slot(num_slot);
    int tower_type = get_tower_type(all, num_slot);

    switch (tower_type) {
        case 1:
            sfSprite_setPosition(all->sprites->upg_tower_1, pos);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->upg_tower_1, NULL);
            upgrade_buttons(all, num_slot);
            break;
        case 2:
            sfSprite_setPosition(all->sprites->upg_tower_2, pos);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->upg_tower_2, NULL);
            upgrade_buttons(all, num_slot);
            break;
        case 3:
            sfSprite_setPosition(all->sprites->upg_tower_3, pos);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->upg_tower_3, NULL);
            upgrade_buttons(all, num_slot);
            break;
        case 4:
            sfSprite_setPosition(all->sprites->upg_tower_4, pos);
            sfRenderWindow_drawSprite(all->windows->window, all->sprites->upg_tower_4, NULL);
            upgrade_buttons(all, num_slot);
            break;
    }
}

void print_no_upgrade(all_var *all, int num_slot)
{
    sfVector2f pos = save_pos_slot(num_slot);
    int tower_type = get_tower_type(all, num_slot);
    if (get_tower_type(all, num_slot) != 0) {
        sfSprite_setPosition(all->sprites->no_upgrades, pos);
        sfRenderWindow_drawSprite(all->windows->window, all->sprites->no_upgrades, NULL);
    }
}


void shop_buttons(all_var *all)
{
    new_button *tower1_button = create_button(500, 60, 100, 100);
    new_button *tower2_button = create_button(800, 60, 100, 100);
    new_button *tower3_button = create_button(1100, 60, 100, 100);
    new_button *tower4_button = create_button(1400, 60, 100, 100);

    if (all->windows->event.type == sfEvtMouseButtonPressed) {
        if (is_button_pressed(tower1_button, all) == 1) {
            all->var->tower_type = 1;
        } else if (is_button_pressed(tower2_button, all) == 1) {
            all->var->tower_type = 2;
        } else if (is_button_pressed(tower3_button, all) == 1) {
            all->var->tower_type = 3;
        } else if (is_button_pressed(tower4_button, all) == 1) {
            all->var->tower_type = 4;
        }
    }
    else {
        if (is_button_pressed(tower1_button, all) == 1)
            sfSprite_setPosition(all->sprites->shine, (sfVector2f){395, 60});
        else if (is_button_pressed(tower2_button, all) == 1)
            sfSprite_setPosition(all->sprites->shine, (sfVector2f){695, 60});
        else if (is_button_pressed(tower3_button, all) == 1)
            sfSprite_setPosition(all->sprites->shine, (sfVector2f){995, 60});
        else if (is_button_pressed(tower4_button, all) == 1)
            sfSprite_setPosition(all->sprites->shine, (sfVector2f){1295, 60});
        else
            sfSprite_setPosition(all->sprites->shine, (sfVector2f){-100, -100});
    }
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->shine, NULL);
}

void slots_buttons(all_var *all)
{
    new_button *slot1 = create_button(305, 500, 200, 150);
    new_button *slot2 = create_button(420, 235, 200, 150);
    new_button *slot3 = create_button(840, 265, 200, 150);
    new_button *slot4 = create_button(1080, 403, 200, 150);
    new_button *slot5 = create_button(1380, 238, 200, 150);
    new_button *slot6 = create_button(350, 670, 200, 150);
    new_button *slot7 = create_button(576, 375, 200, 150);
    new_button *slot8 = create_button(840, 480, 200, 150);
    new_button *slot9 = create_button(1325, 515, 200, 150);
    new_button *slot10 = create_button(1565, 350, 200, 150);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 0.5) {
        if (is_button_pressed(slot1, all) == 1) {
            write_tower_in_slot(all, 1, all->var->tower_type);
        } else if (is_button_pressed(slot2, all) == 1) {
            write_tower_in_slot(all, 2, all->var->tower_type);
        } else if (is_button_pressed(slot3, all) == 1) {
            write_tower_in_slot(all, 3, all->var->tower_type);
        } else if (is_button_pressed(slot4, all) == 1) {
            write_tower_in_slot(all, 4, all->var->tower_type);
        } else if (is_button_pressed(slot5, all) == 1) {
            write_tower_in_slot(all, 5, all->var->tower_type);
        } else if (is_button_pressed(slot6, all) == 1) {
            write_tower_in_slot(all, 6, all->var->tower_type);
        } else if (is_button_pressed(slot7, all) == 1) {
            write_tower_in_slot(all, 7, all->var->tower_type);
        } else if (is_button_pressed(slot8, all) == 1) {
            write_tower_in_slot(all, 8, all->var->tower_type);
        } else if (is_button_pressed(slot9, all) == 1) {
            write_tower_in_slot(all, 9, all->var->tower_type);
        } else if (is_button_pressed(slot10, all) == 1) {
            write_tower_in_slot(all, 10, all->var->tower_type);
        }
        sfClock_restart(all->clocks->clock_button);
    }
}

void delete_selection(all_var *all)
{
    new_button *trash_button = create_button(1500, 40, 100, 100);
    sfVector2f pos = (sfVector2f){1500, 120};

    sfSprite_setPosition(all->sprites->trash, pos);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->trash, NULL);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && is_button_pressed(trash_button, all)) {
        all->var->tower_type = 0;
    }
}

void print_level(all_var *all, t_info_slots *tmp_slots)
{
    if (tmp_slots->type_tower != 0) {
        sfVector2f pos = tmp_slots->pos_slot;
        pos.y += 200;
        pos.x += 32;
        
        sfText_setColor(all->texts->text2, sfColor_fromRGB(255, 255, 255));
        sfText_setCharacterSize(all->texts->text2, 20);
        sfText_setPosition(all->texts->text2, pos);
        sfText_setString(all->texts->text2, "Level: ");
        sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
        pos.x += 72;
        sfText_setPosition(all->texts->text2, pos);
        sfText_setString(all->texts->text2, my_return_time(tmp_slots->level_tower));
        sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
        sfText_setCharacterSize(all->texts->text2, 30);
    }
}

int all_enemies_dead_pass(all_var *all)
{
    int i = 0;
    t_info_soldiers *tmp = all->soldiers->next;

    while (i < all->var->enemy_waves) {
        if (tmp->live > 0) {
            return (0);
        }
        tmp = tmp->next;
        i++;
    }
    all->var->sound_steps = 0;
    sfClock_restart(all->clocks->clock_between_waves);
    return (1);
}

void set_num_soldiers(all_var *all)
{
    int i = 0;
    t_info_soldiers *tmp = all->soldiers->next;

    while (tmp != NULL) {
        if (i < all->var->enemy_waves) {
            tmp->live = 100;
            tmp->pos_soldier = (sfVector2f) {0, 700};
            tmp->select_soldier_health =  (sfIntRect) {0, 0, 450, 50};
        }
        else {
            tmp->live = 0;
            tmp->pos_soldier = (sfVector2f) {0, 700};
            tmp->select_soldier_health =  (sfIntRect) {0, 0, 450, 50};
        }
        i++;
        tmp = tmp->next;
    }
    sfClock_restart(all->clocks->clock_between_waves);
}

void reset_game(all_var *all)
{
    t_info_slots *tmp = all->slots->next;

    while (tmp != NULL) {
        tmp->type_tower = 0;
        tmp->level_tower = 1;
        tmp->show_upgrade = 0;
        tmp = tmp->next;
    }

    all->var->enemy_waves = 1;
    all->var->num_lives = 5;
    all->var->money = 1000;
    all->var->score = 0;
    all->var->enemy_killed = 0;
    sfClock_restart(all->clocks->clock_timeplaying);
}

void print_page_game(all_var *all)
{   
    int i = 0;
    int restart_clock = 1;
    // POT VARIAR SEGONS EL NIVELL SERA UN SPRITE O UN ALTRE
    all->clocks->time_playing= sfClock_getElapsedTime(all->clocks->clock_timeplaying);
    all->clocks->time_between_waves= sfClock_getElapsedTime(all->clocks->clock_between_waves);
    
    sfSprite_setPosition(all->sprites->background, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->background, NULL);
    
    if (all->var->enemy_waves > 1 && all_enemies_dead_pass(all) != 0) {
        all->var->page = 6;
    }
    if (all->var->enemy_waves <= 1 && all_enemies_dead_pass(all) != 0 ) {
        set_num_soldiers(all);
        all->var->enemy_waves++;
    }


    /////// STEPS SOUND

    if (all_enemies_dead_pass(all) == 0 && all->var->sound_steps == 0 && all->var->sound_on == 1) {
        sfMusic_play(all->sounds->soldiers_steps);
        all->var->sound_steps = 1;
    }
    else if (all_enemies_dead_pass(all) != 0 && all->var->sound_steps == 1 || all->var->sound_on == 0){
        sfMusic_pause(all->sounds->soldiers_steps);

    }
    /////// STEPS SOUND END

    //SHOP
    print_shop(all);
    //shop_buttons(all);
    slots_buttons(all);
    delete_selection(all);

    //IMPRESIÓ TORRES 1 A 5
    t_info_slots *tmp_slots = all->slots->next;
    while (tmp_slots->next != NULL) {
        ///Passarho a function pointers
        if (tmp_slots->num_slot >= 1 && tmp_slots->num_slot <= 5) {
            print_tower_in_slot(all, tmp_slots);
            if (tmp_slots->show_upgrade == 1 && tmp_slots->level_tower < 3)
                print_upgrade(all, tmp_slots->num_slot);
            else if (tmp_slots->show_upgrade == 1 )
                print_no_upgrade(all, tmp_slots->num_slot);
            print_level(all, tmp_slots);
        }
        tmp_slots = tmp_slots->next;
    }
    ///////////// Movment player
    t_info_soldiers *tmp = all->soldiers->next;
    while (tmp->next != NULL) {
        if (tmp->num_soldier == 0 || tmp->prev->pos_soldier.x >= 100) {
            if (tmp->live > 0)
                print_char(all, tmp);
        }
        tmp = tmp->next;
    }
    //////////////// IMPRESIO TORRES 6 A 10
    tmp_slots = all->slots->next;
    while (tmp_slots->next != NULL) {
        if (tmp_slots->num_slot >= 6 && tmp_slots->num_slot <= 10) {
            print_tower_in_slot(all, tmp_slots);
            if (tmp_slots->show_upgrade == 1 && tmp_slots->level_tower < 3)
                print_upgrade(all, tmp_slots->num_slot);
            else if (tmp_slots->show_upgrade == 1 )
                print_no_upgrade(all, tmp_slots->num_slot);
            print_level(all, tmp_slots);
        }
        tmp_slots = tmp_slots->next;
    }
    print_castle_live(all);
    print_tower_in_mouse(all);
    sfRenderWindow_display(all->windows->window);
}

void game_over_page(all_var *all)
{
    new_button *exit_button = create_button(1265, 120, 95, 90);
    new_button *main = create_button(565, 745, 370, 170);
    new_button *play_again = create_button(1000, 745, 370, 170);

    sfMusic_pause(all->sounds->soldiers_steps);

    all->clocks->time_button = sfClock_getElapsedTime(all->clocks->clock_button);
    if (all->windows->event.type == sfEvtMouseButtonPressed
    && sfTime_asSeconds(all->clocks->time_button) > 1) {
        if (is_button_pressed(exit_button, all) == 1) {
            exit(0);
        } else if (is_button_pressed(main, all) == 1) {
            all->var->page = 2;
        } else if (is_button_pressed(play_again, all) == 1) {
            all->var->page = 5;
            reset_game(all);
        }
        sfClock_restart(all->clocks->clock_button);
    }
}

void print_game_over(all_var *all)
{
    game_over_page(all);
    sfSprite_setPosition(all->sprites->game_over, all->vectors->pos_origin);
    sfRenderWindow_drawSprite(all->windows->window, all->sprites->game_over, NULL);
    sfText_setCharacterSize(all->texts->text2, 70);
    sfText_setColor(all->texts->text2, sfColor_fromRGB(255, 255, 255));//213, 153, 65

    sfText_setPosition(all->texts->text2, (sfVector2f) {1100, 360});
    sfText_setString(all->texts->text2, my_return_time(all->var->enemy_killed));
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    sfText_setPosition(all->texts->text2, (sfVector2f) {1100, 480});
    sfText_setString(all->texts->text2, my_return_time(all->var->enemy_waves - 1));
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);    
    sfText_setPosition(all->texts->text2, (sfVector2f) {1100, 615});
    sfText_setString(all->texts->text2, my_return_time(sfTime_asSeconds(all->clocks->time_playing)));
    sfRenderWindow_drawText(all->windows->window, all->texts->text2, NULL);
    
    sfRenderWindow_display(all->windows->window);
}
