#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct Node Node;
struct Node {
  int data;
  Node *next;
  Node *prev;
};

typedef struct Dequeue Dequeue;
struct Dequeue {
  int count;
  Node *front;
  Node *rear;
};

Dequeue *createDequeue();
void freeDequeue(Dequeue *dq);
void appendDequeue(Dequeue *dq, int data);
void appendLeftDequeue(Dequeue *dq, int data);
int popDequeue(Dequeue *dq);
int popLeftDequeue(Dequeue *dq);
int isEmptyDequeue(Dequeue *dq);
void displayDequeue(Dequeue *dq);

#endif  // DEQUEUE_H
