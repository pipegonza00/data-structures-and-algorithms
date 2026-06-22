#ifndef DYNAMIC_H
#define DYNAMIC_H

typedef struct {    
    int *arr;
    int size;
    int capacity;

} Dynamic;

Dynamic* create_array(int capacity);
void fill_array(Dynamic *arr, int n);
void fill_array_random(Dynamic *arr, int n, int min, int max);
void fill_array_from_input(Dynamic *arr, int n);
int strict_push_back(Dynamic *arr, int value);
void push_back(Dynamic *arr, int value);
void remove_at(Dynamic *arr, int index);
void free_array(Dynamic *arr);
void print_array(Dynamic *arr);


#endif