#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue{
    QueueNode *front;
    QueueNode *rear;
    int size;

} Queue;

Queue *createQueue();
int isEmpty(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int peek(Queue *queue);
void freeQueue(Queue *queue);
void printQueue(Queue *queue);


#endif // QUEUE_H