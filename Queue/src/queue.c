#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    if(queue == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;

}

int isEmpty(Queue *queue){
    return queue->size == 0;

}

void enqueue(Queue *queue, int value){
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));

    if(queue == NULL){
        fprintf(stderr, "Queue is NULL\n");
        exit(EXIT_FAILURE);
    }
    
    if(node == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->next = NULL;

    if(queue->rear == NULL){
        queue->front = node;
        queue->rear = node;
    
    }else{
        queue->rear->next = node;
        queue->rear = node;
    
    }  

    queue->size++;

}

int dequeue(Queue *queue){
    int dequeue_value;
    QueueNode *node;

    if(queue->size == 0){
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    };

    node = queue->front;
    dequeue_value = node->data;

    queue->front = node->next;
    queue->size--;

    free(node);

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    return dequeue_value;

}

int peek(Queue *queue){
    return queue->front->data;

}

void freeQueue(Queue *queue){
    QueueNode *current, *temp;

    current = queue->front;

    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);

}

void printQueue(Queue *queue){
    QueueNode *current = queue->front;

    printf("Queue: front -> ");
    while(current != NULL){
        printf("[%d] -> ", current->data);
        current = current->next;
    
    }
    printf("rear\n");

}