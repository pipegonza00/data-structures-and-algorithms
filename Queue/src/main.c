#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printQueue(queue);

    printf("dequeue: %d\n", dequeue(queue));
    printQueue(queue);
    

    return 0;
    
}