#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

typedef struct CircularQueue CircularQueue;

struct CircularQueue {
  int size;
  int front;
  int count;
  int *arr;
};

CircularQueue *createCircularQueue(int size);
void freeCircularQueue(CircularQueue *cq);
void pushCircularQueue(CircularQueue *cq, int data);
int popCircularQueue(CircularQueue *cq);
int isFullCircularQueue(CircularQueue *cq);
int isEmptyCircularQueue(CircularQueue *cq);
void displayCircularQueue(CircularQueue *cq);

#endif  // CIRCULARQUEUE_H
