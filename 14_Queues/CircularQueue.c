#include "CircularQueue.h"

#include <stdlib.h>
#include <stdio.h>

CircularQueue *createCircularQueue(int size) {
    CircularQueue *cq = (CircularQueue *) malloc(sizeof(CircularQueue));
    cq->size = size;
    cq->front = 0;
    cq->count = 0;
    cq->arr = (int *) malloc(cq->size * sizeof(int));
    return cq;
}

void freeCircularQueue(CircularQueue *cq) {
    free(cq->arr);
    free(cq);
}

void pushCircularQueue(CircularQueue *cq, int data) {
    if (isFullCircularQueue(cq)) {
        printf("Error: Circular Queue is full\n");
        exit(1);
    }
    int rear = (cq->front + cq->count) % cq->size;
    cq->arr[rear] = data;
    cq->count++;
}

int popCircularQueue(CircularQueue *cq) {
    if (isEmptyCircularQueue(cq)) {
        printf("Error: Circular Queue is empty\n");
        exit(1);
    }

    int val = cq->arr[cq->front];
    cq->front++;
    cq->front %= cq->size;
    cq->count--;
    return val;
}

int isFullCircularQueue(CircularQueue *cq) {
    return cq->count == cq->size;
}

int isEmptyCircularQueue(CircularQueue *cq) {
    return cq->count == 0;
}

void displayCircularQueue(CircularQueue *cq) {
    printf("[ ");
    for (int i = 0; i < cq->count; i++) {
        int idx = (cq->front + i) % cq->size;
        printf("%d ", cq->arr[idx]);
    }
    printf("]\n");
}
