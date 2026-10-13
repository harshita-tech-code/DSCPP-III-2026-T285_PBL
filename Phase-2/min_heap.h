#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int orderID;
    int studentID;
    int remainingMinutes; // Sorting key for Min-Heap priority
} TiffinOrder;

typedef struct {
    TiffinOrder* orders;
    int capacity;
    int size;
} DispatchMinHeap;

DispatchMinHeap* createMinHeap(int capacity);
void insertMinHeap(DispatchMinHeap* heap, int orderID, int studentID, int minutes);
TiffinOrder extractMinHeap(DispatchMinHeap* heap);
void freeMinHeap(DispatchMinHeap* heap);

#endif