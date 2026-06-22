#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"

#define MAX_SIZE 20

int main() {
    Node* head = NULL;

    print_list(head);

    for(int i = 0; i < MAX_SIZE; i++){
        push_front(&head, (i + 1) * 10);
    }

    print_list(head);

    for(int i = 0; i < 3; i++){
        push_back(&head, (i + 4) * 10);
    }

    print_list(head);
   
    remove_node(&head, 20);
    remove_node(&head, 40);

    print_list(head);

    free_list(head);
    return 0;
}
   