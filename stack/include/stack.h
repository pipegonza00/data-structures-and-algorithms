#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode;

typedef struct Stack{
    struct StackNode* top;
    int size;
} Stack;

Stack *create_stack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack *stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);
void printStack(Stack* stack);

#endif //STACK_H