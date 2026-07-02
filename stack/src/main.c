#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 10
#define POP_COUNT 5

int main(){
    Stack* stack = create_stack();   

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    
    printStack(stack);

    printf("pop: %d\n", pop(stack));

    printStack(stack);

    return 0;
}