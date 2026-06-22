#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "searching.h"
#include "statistics.h"
#include "dynamic.h"
#include "menu.h"

int main(){
    int running = 1, filled = 0;
    Dynamic *arr = create_array(1000);

    printf("Welcome to the Array Tools Program!\n");
    printf("This program allows you to create, manipulate, sort, search, and analyze arrays.\n");
    printf("we start with a default empty array of capacity 10 and size 0, but you can fill it with your own values or generate random numbers.\n");

    while(running){
        if(!filled){
            printf("Please fill the array before accessing other functionalities.\n");
            fill_array_menu(arr);
            filled = 1;

        }else{
            show_menu();
            int choice = get_choice();
            handle_choice(choice, arr);
        }
        
    }

    free_array(arr);

    return 0;

}