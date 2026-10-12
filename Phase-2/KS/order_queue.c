#include "order_queue.h"
#include <string.h>

/* Initialize empty queue */
void initQueue(PriorityQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueEmpty(const PriorityQueue* q) {
    return q->count == 0;
}

bool isQueueFull(const PriorityQueue* q) {
    return q->count == MAX_ORDERS;
}

/* Enqueue with insertion sort to keep earliest deadlines in front (DS Unit 2) */
bool enqueueOrder(PriorityQueue* q, OrderItem item) {
    if (isQueueFull(q)) {
        printf("Queue Overflow: Cannot add order %d\n", item.orderID);
        return false;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = item;
    } else {
        /* Circular index shifting to insert based on deliveryWindowMinutes */
        int i = q->count - 1;
        while (i >= 0) {
            int currIdx = (q->front + i) % MAX_ORDERS;
            int nextIdx = (q->front + i + 1) % MAX_ORDERS;

            if (q->data[currIdx].deliveryWindowMinutes > item.deliveryWindowMinutes) {
                q->data[nextIdx] = q->data[currIdx];
                i--;
            } else {
                break;
            }
        }
        int insertIdx = (q->front + i + 1) % MAX_ORDERS;
        q->data[insertIdx] = item;
        q->rear = (q->rear + 1) % MAX_ORDERS;
    }

    q->count++;
    return true;
}

/* Dequeue the highest priority order from the front */
bool dequeueOrder(PriorityQueue* q, OrderItem* outItem) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow: No active orders to dispatch\n");
        return false;
    }

    *outItem = q->data[q->front];
    q->front = (q->front + 1) % MAX_ORDERS;
    q->count--;
    return true;
}

void displayQueue(const PriorityQueue* q) {
    printf("\n=== Active Dispatch Order Queue ===\n");
    if (isQueueEmpty(q)) {
        printf("Queue is currently empty.\n");
        printf("===================================\n");
        return;
    }

    for (int i = 0; i < q->count; i++) {
        int idx = (q->front + i) % MAX_ORDERS;
        printf("  [Pos %2d] Order ID: %-5d | Target Window: %2d mins | Token: %s\n",
               i + 1, q->data[idx].orderID, q->data[idx].deliveryWindowMinutes, q->data[idx].studentToken);
    }
    printf("===================================\n");
}