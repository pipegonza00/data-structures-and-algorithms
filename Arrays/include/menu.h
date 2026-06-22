#ifndef MENU_H
#define MENU_H

#include "dynamic.h"

void show_menu();
int get_choice();
void handle_choice(int choice, Dynamic *arr);
void fill_array_menu(Dynamic *arr);
void add_remove_menu(Dynamic *arr);
void sorting_menu(Dynamic *arr);
void searching_menu(Dynamic *arr);
void statistics_menu(Dynamic *arr);
void exit_program();

#endif