#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 10
#define POP_COUNT 5

int main(){
    Stack* stack = create_stack();   

    for(int i = 0; i < N; i++){
        push(stack, rand() % 10);
    }

    printStack(stack);

    printf("peek: %d\n", peek(stack));
    
    for(int i = 0; i < POP_COUNT; i++){
        printf("pop: %d\n", pop(stack));
        printStack(stack);
    }

    printf("is empty: %d\n", is_empty(stack));

    for(int i = 0; i < N - POP_COUNT; i++){
        pop(stack);
        printStack(stack);
    }

    printf("is empty: %d\n", is_empty(stack));

    return 0;
}