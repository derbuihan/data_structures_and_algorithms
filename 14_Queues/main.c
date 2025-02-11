
#include <stdio.h>
#include "CircularQueue.h"

int main() {
    CircularQueue *cq = createCircularQueue(5);

    for (int i = 1; i <= 5; i++) {
        printf("Pushing %d: ", i * 10);
        pushCircularQueue(cq, i * 10);
        displayCircularQueue(cq);
    }

    if (isFullCircularQueue(cq)) {
        printf("Circular Queue is full\n");
    }

    for (int i = 1; i <= 5; i++) {
        printf("Popping ");
        printf("%d: ", popCircularQueue(cq));
        displayCircularQueue(cq);
    }

    if (isEmptyCircularQueue(cq)) {
        printf("Circular Queue is empty\n");
    }

    freeCircularQueue(cq);
    return 0;
}
