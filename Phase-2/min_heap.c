#include "min_heap.h"

DispatchMinHeap* createMinHeap(int capacity) {
    DispatchMinHeap* heap = (DispatchMinHeap*)malloc(sizeof(DispatchMinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->orders = (TiffinOrder*)malloc(capacity * sizeof(TiffinOrder));
    return heap;
}

void swapOrders(TiffinOrder* a, TiffinOrder* b) {
    TiffinOrder temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(DispatchMinHeap* heap, int orderID, int studentID, int minutes) {
    if (heap->size >= heap->capacity) {
        printf("Heap Overflow! Maximum dispatches queued.\n");
        return;
    }
    
    int i = heap->size++;
    heap->orders[i].orderID = orderID;
    heap->orders[i].studentID = studentID;
    heap->orders[i].remainingMinutes = minutes;

    // Up-heap bubble sort to maintain Min-Heap property (DS Unit 4)
    while (i != 0 && heap->orders[(i - 1) / 2].remainingMinutes > heap->orders[i].remainingMinutes) {
        swapOrders(&heap->orders[i], &heap->orders[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(DispatchMinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->orders[left].remainingMinutes < heap->orders[smallest].remainingMinutes)
        smallest = left;
    if (right < heap->size && heap->orders[right].remainingMinutes < heap->orders[smallest].remainingMinutes)
        smallest = right;

    if (smallest != i) {
        swapOrders(&heap->orders[i], &heap->orders[smallest]);
        heapifyDown(heap, smallest);
    }
}

TiffinOrder extractMinHeap(DispatchMinHeap* heap) {
    if (heap->size <= 0) {
        TiffinOrder empty = {-1, -1, -1};
        return empty;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->orders[0];
    }

    TiffinOrder root = heap->orders[0];
    heap->orders[0] = heap->orders[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}

void freeMinHeap(DispatchMinHeap* heap) {
    free(heap->orders);
    free(heap);
}