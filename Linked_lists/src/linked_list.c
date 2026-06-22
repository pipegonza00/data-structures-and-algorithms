#include "Linked_list.h"
#include <stdio.h>
#include <stdlib.h>


Node* create_node(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL){
        fprintf(stderr, "Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;

}

void push_front(Node** head, int value){
    Node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;

}

void push_back(Node** head, int value){
    Node* new_node = create_node(value);

    if(head == NULL){
        *head = new_node;
        return;
    }

    Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;

}

void remove_node(Node** head, int value){
    Node *temp, *current;
    
    if(*head != NULL){
        
        if((*head)->data == value){
            temp = *head;
            *head = (*head)->next;
            free(temp);
            return;
        
        }

        current = *head;
        while(current->next != NULL && current->next->data != value) current = current->next;
        
        if(current->next != NULL){
            temp = current->next;
            current->next = current->next->next;    
            free(temp);
        }

    }

}

void free_list(Node* head){
    Node* temp;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    
    }

}

void print_list(Node* head){
    
    printf("Linked List:\n");
    
    while(head != NULL){
        printf(" [%d] ->", head->data);
        head = head->next;
    }
    
    printf(" NULL\n");

}