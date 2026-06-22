#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* create_node(int value);
void push_front(Node** head, int value);
void push_back(Node** head, int value);
void remove_node(Node** head, int value);
void free_list(Node* head);
void print_list(Node* head);

#endif // LINKED_LIST_H