#ifndef ORDER_QUEUE_H
#define ORDER_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ORDERS 30

/* Delivery order struct holding deadline window (DS Unit 2) */
typedef struct OrderItem {
    int orderID;
    int deliveryWindowMinutes; /* Urgency metric: smaller is higher priority */
    char studentToken[20];
} OrderItem;

/* Circular Priority Queue Representation (DS Unit 2) */
typedef struct PriorityQueue {
    OrderItem data[MAX_ORDERS];
    int front;
    int rear;
    int count;
} PriorityQueue;

/* Function prototypes */
void initQueue(PriorityQueue* q);
bool isQueueEmpty(const PriorityQueue* q);
bool isQueueFull(const PriorityQueue* q);
bool enqueueOrder(PriorityQueue* q, OrderItem item);
bool dequeueOrder(PriorityQueue* q, OrderItem* outItem);
void displayQueue(const PriorityQueue* q);

#endif /* ORDER_QUEUE_H */