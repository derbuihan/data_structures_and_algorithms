#include <stdio.h>

#include "Dequeue.h"

int main() {
  Dequeue *dq = createDequeue();

  for (int i = 1; i <= 3; i++) {
    printf("Append %d: ", i * 10);
    appendDequeue(dq, i * 10);
    displayDequeue(dq);

    printf("Append Left %d: ", i * 100);
    appendLeftDequeue(dq, i * 100);
    displayDequeue(dq);
  }

  for (int i = 1; i <= 3; i++) {
    printf("Pop %d: ", popDequeue(dq));
    displayDequeue(dq);
    printf("Pop Left %d: ", popLeftDequeue(dq));
    displayDequeue(dq);
  }

  freeDequeue(dq);
  return 0;
}
