#include "Dequeue.h"

#include <stdio.h>
#include <stdlib.h>

Dequeue *createDequeue() {
  Dequeue *dq = malloc(sizeof(Dequeue));
  dq->count = 0;
  dq->front = NULL;
  dq->rear = NULL;
  return dq;
}

static void freeNode(Node *node) { free(node); }

void freeDequeue(Dequeue *dq) {
  Node *curr = dq->front;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    freeNode(temp);
  }
  free(dq);
}

static Node *createNode(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void appendDequeue(Dequeue *dq, int data) {
  Node *node = createNode(data);

  if (dq->count == 0) {
    dq->front = node;
    dq->rear = node;
    dq->count++;
    return;
  }

  dq->rear->next = node;
  node->prev = dq->rear;
  dq->rear = node;
  dq->count++;
}

void appendLeftDequeue(Dequeue *dq, int data) {
  Node *node = createNode(data);

  if (dq->count == 0) {
    dq->front = node;
    dq->rear = node;
    dq->count++;
    return;
  }

  node->next = dq->front;
  dq->front->prev = node;
  dq->front = node;
  dq->count++;
}

int popDequeue(Dequeue *dq) {
  if (isEmptyDequeue(dq)) {
    printf("Error: Dequeue is empty\n");
    exit(1);
  }

  Node *temp = dq->rear;
  int val = temp->data;
  dq->rear = temp->prev;
  freeNode(temp);
  dq->count--;

  if (dq->rear) {
    dq->rear->next = NULL;
  }

  if (dq->count == 0) {
    dq->front = NULL;
  }

  return val;
}

int popLeftDequeue(Dequeue *dq) {
  if (isEmptyDequeue(dq)) {
    printf("Error: Dequeue is empty\n");
    exit(1);
  }

  Node *temp = dq->front;
  int val = temp->data;
  dq->front = temp->next;
  freeNode(temp);
  dq->count--;

  if (dq->front) {
    dq->front->prev = NULL;
  }

  if (dq->count == 0) {
    dq->rear = NULL;
  }

  return val;
}

int isEmptyDequeue(Dequeue *dq) { return dq->count == 0; }

void displayDequeue(Dequeue *dq) {
  Node *curr = dq->front;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
