#include <stdio.h>
#include <stdlib.h>
#include <dynamic.h>

Dynamic *create_array(int capacity){
    Dynamic *arr = (Dynamic *)malloc(sizeof(Dynamic));
    arr->arr = (int *)calloc(capacity, sizeof(int));

    if(arr->arr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);

    }

    arr->size = 0;
    arr->capacity = capacity;

    return arr;

}

void fill_array(Dynamic *arr, int n){
    for(int i = 0; i < n; i++){
        arr->arr[i] = i;
    }
    arr->size = n;
}

void fill_array_random(Dynamic *arr, int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr->arr[i] = min + rand() % (max - min + 1);
    }
    arr->size = n;
}

void fill_array_from_input(Dynamic *arr, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arr->arr[i]);
    }
    arr->size = n;
}

int strict_push_back(Dynamic *arr, int value){
    int result = 1;
    
    if(arr->size == arr->capacity){
        fprintf(stderr, "Array is full, use dynamic push_back instead\n");
        return result;
    } else {
        arr->arr[arr->size] = value;
        arr->size++;
        result = 0;
    }

    return result;

}

void push_back(Dynamic *arr, int value){
    
    if(arr->size == arr->capacity){
        arr->capacity *= 2;
        arr->arr = (int *)realloc(arr->arr, arr->capacity * sizeof(int));

        if(arr->arr == NULL){
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);

        }

    }

    arr->arr[arr->size] = value;
    arr->size++;

}

void remove_at(Dynamic *arr, int index){

    if(index < 0 || index >= arr->size){
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for(int i = index; i < arr->size -1; i++){
        arr->arr[i] = arr->arr[i + 1];
    }

    arr->size--;
    
}

void free_array(Dynamic *arr){
    free(arr->arr);
    free(arr);
}


void print_array(Dynamic *arr){
    printf("array:\n");
    for(int i = 0; i < arr->size; i++){
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}


