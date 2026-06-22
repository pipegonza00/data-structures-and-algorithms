#include <stdio.h>
#include <stdlib.h>

int *setup_array(int size){
    int *arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return arr;
}

int *fill_array(int *arr, int size){
    
    for (int i = 0; i < size; i++){
        arr[i] = i*i - i + 1; 
    } 

    return arr;
}

void print_array(int *arr, int size){
    printf("array:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]){

    int n = 5;
    int *arr = setup_array(n);
    
    fill_array(arr, n);
    print_array(arr, n);
    
    return 0;
}