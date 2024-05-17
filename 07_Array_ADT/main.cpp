#include <cstdio>
#include <cstdlib>

typedef struct Array {
    int A[10];
    int length;
    int size;
} Array;

void Display(Array arr) {
    printf("\nElements are\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

void Append(Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(Array *arr, int index, int x) {
    if (index < 0 || index > arr->length) {
        return;
    }

    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
}

int main() {
    Array arr = {.A = {2, 4, 6, 8, 10},
                 .length = 5,
                 .size = 10};
    Display(arr);

    Append(&arr, 12);
    Display(arr);

    Insert(&arr, 2, 5);
    Display(arr);

    Insert(&arr, 0, 0);
    Display(arr);

    return 0;
}
