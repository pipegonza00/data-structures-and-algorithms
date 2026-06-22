#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack *create_stack(){
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));

    if(stack == NULL){
        fprintf(stderr, "Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    stack->size = 0;

    return stack;

}


void push(Stack* stack, int value){
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));

    if(node == NULL){
        fprintf(stderr, "Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    node->next = stack->top;
    node->data = value;

    stack->top = node;
    stack->size++;
    
}

int pop(Stack *stack){
    
    int popped_value;
    StackNode *node;

    node = stack->top;
    popped_value = node->data;

    stack->top = stack->top->next;
    stack->size--;

    free(node);

    return popped_value;

}

int peek(Stack *stack){
    return stack->top->data;

}

int is_empty(Stack *stack){
    return stack->size > 0 ? 0 : 1;

}

void free_stack(Stack *stack){
    StackNode *current = stack->top;
    StackNode *temp;

    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }

    free(stack);

}

void printStack(Stack* stack) {
    StackNode* current = stack->top;

    printf("TOP -> ");

    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");

}
