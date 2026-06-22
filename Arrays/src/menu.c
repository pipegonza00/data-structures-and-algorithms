#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "dynamic.h"
#include "sorting.h"
#include "searching.h"
#include "statistics.h"

void show_menu() {
    printf("Menu:\n");
    printf("1. Add elements or remove elements\n");
    printf("2. Sorting algorithms\n");
    printf("3. Searching algorithms\n");
    printf("4. Statistical functions\n");
    printf("0. Exit\n");
}

int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void handle_choice(int choice, Dynamic *arr) {
    switch (choice) {
        case 1:
            add_remove_menu(arr);
            break;
        case 2:
            sorting_menu(arr);
            break;
        case 3:
            searching_menu(arr);
            break;
        case 4:
            statistics_menu(arr);
            break;
        case 0:
            exit_program();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void fill_array_menu(Dynamic *arr) {
    int choice, min, max, valid = 0;
    printf("Fill Array Menu:\n");
    printf("1. Fill with sequential numbers\n");
    printf("2. Fill with random numbers\n");
    printf("3. Fill from user input\n");

    choice = get_choice();
    switch (choice) {
        case 1:
            fill_array(arr, arr->capacity);
            printf("Array filled with sequential numbers.\n");
            print_array(arr);
            break;
        
        case 2:
            while(!valid){
                printf("Please enter the range for random numbers (min max): ");
                if(scanf("%d %d", &min, &max) == 2 && min <= max && min >= 0 && max >= 0){
                    valid = 1;
                } else {
                    printf("Invalid input. Please enter two integers where min <= max and both are non-negative.\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
            }

            fill_array_random(arr, arr->capacity, min, max);
            printf("Array filled with random numbers.\n");
            print_array(arr);

            break;

        case 3:
            printf("Please enter %d integers:\n", arr->capacity);
            fill_array_from_input(arr, arr->capacity);
            printf("Array filled with user input.\n");
            print_array(arr);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void add_remove_menu(Dynamic *arr) {
    int choice, value, index;
    printf("Add/Remove Menu:\n");
    printf("1. Add element with strict push_back\n");
    printf("2. Add element with dynamic push_back\n");
    printf("3. Remove element\n");

    choice = get_choice();
    switch (choice) {
        case 1:
            printf("Enter value to add: ");
            printf("(Note: This will fail if the array is full)\n");
            scanf("%d", &value);
            
            if(!strict_push_back(arr, value)){
                printf("Element added with strict push_back.\n");
                print_array(arr);
            
            }

            break;

        case 2:
            printf("Enter value to add: ");
            scanf("%d", &value);
            push_back(arr, value);
            printf("Element added with dynamic push_back.\n");
            
            print_array(arr);
            
            break;

        case 3:
            printf("Enter index of element to remove: ");
            scanf("%d", &index);
            remove_at(arr, index);
            printf("Element removed.\n");
            
            print_array(arr);

            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void sorting_menu(Dynamic *arr) {
    int choice;
    clock_t start, end;
    
    printf("Sorting Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Shuffle\n");
    // Add more sorting algorithms as needed

    choice = get_choice();
    switch (choice) {
        case 1:
            printf("Sorting with Bubble Sort...\n");
            print_array(arr);

            start = clock();
            bubble_sort(arr->arr, arr->size);
            end = clock();
            
            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            break;
        case 2:
            printf("Sorting with Insertion Sort...\n");
            print_array(arr);

            start = clock();
            insertion_sort(arr->arr, arr->size);
            end = clock();

            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 3:
            printf("Sorting with Selection Sort...\n");
            print_array(arr);

            start = clock();
            selection_sort(arr->arr, arr->size);
            end = clock();

            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 4:
            printf("Sorting with Quick Sort...\n");
            print_array(arr);

            start = clock();
            quick_sort(arr->arr, 0, arr->size - 1);
            end = clock();

            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 5:
            
            printf("Sorting with Merge Sort...\n");
            print_array(arr);

            start = clock();
            merge_sort(arr->arr, arr->size);
            end = clock();

            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        case 6:
            
            printf("Shuffling the array...\n");
            print_array(arr);

            start = clock();
            shuffle(arr->arr, arr->size);
            end = clock();

            print_array(arr);
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }    
}

void searching_menu(Dynamic *arr) {
    int choice, index, value;
    clock_t start, end;
    printf("Searching Menu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    // Add more searching algorithms as needed

    choice = get_choice();
    switch (choice) {
        case 1:
            printf("Enter value to search for: ");
            scanf("%d", &value);
            start = clock();
            index = linear_search(arr->arr, arr->size, value);
            end = clock();
            
            
            if (index != -1) {
                printf("Value found at index: %d\n", index);
            } else {
                printf("Value not found in the array.\n");
            }

            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            break;

        case 2:
            printf("Enter value to search for: ");
            scanf("%d", &value);
            
            start = clock();
            index = binary_search(arr->arr, 0, arr->size - 1, value);
            end = clock();
            
            if (index != -1) {
                printf("Value found at index: %d\n", index);
            } else {
                printf("Value not found in the array.\n");
            }
            printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            
            break;

        default:
            printf("Invalid choice. Please try again.\n");

    }
}

void statistics_menu(Dynamic *arr) {
    int choice;
    printf("Statistics Menu:\n");
    printf("1. Mean\n");
    printf("2. Median\n");
    printf("3. Mode\n");
    // Add more statistical functions as needed

    choice = get_choice();
    switch (choice) { 
        case 1:
            // Call mean function
            break;
        case 2:
            // Call median function
            break;
        case 3:
            // Call mode function
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void exit_program() {
    printf("Exiting program. Goodbye!\n");
    exit(0);
}