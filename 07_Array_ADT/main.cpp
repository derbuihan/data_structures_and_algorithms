#include <cstdio>
#include <cstdlib>

typedef struct Array {
    int A[20];
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

void InsertSort(Array *arr, int x) {
    if (arr->length == arr->size) return;
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) return 0;
    }
    return 1;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Rearrange(Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

Array *Merge(Array *arr1, Array *arr2) {
    Array *arr3 = (Array *) malloc(sizeof(Array));

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        if (arr1->A[i] >= arr2->A[j]) arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->size = 20;
    arr3->length = arr1->length + arr2->length;

    return arr3;
}

Array *Union(Array *arr1, Array *arr2) {
    Array *arr3 = (Array *) malloc(sizeof(Array));

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr1->A[i] > arr2->A[j]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++) arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++) arr3->A[k++] = arr2->A[j];
    arr3->size = 20;
    arr3->length = k;

    return arr3;
}

Array *Intersection(Array *arr1, Array *arr2) {
    Array *arr3 = (Array *) malloc(sizeof(Array));

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr1->A[i] > arr2->A[j]) {
            j++;
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->size = 20;
    arr3->length = k;

    return arr3;
}

Array *Defference(Array *arr1, Array *arr2) {
    Array *arr3 = (Array *) malloc(sizeof(Array));

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr1->A[i] > arr2->A[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->size = 20;
    arr3->length = k;

    return arr3;
}

int main() {
    Array arr1 = {.A = {2, 5, 10, 12, 15, 21}, .length = 6, .size = 20};
    Array arr2 = {.A = {1, 5, 10, 17, 21, 22}, .length = 6, .size = 20};
    Display(arr1);
    Display(arr2);

    Array *arr3 = Defference(&arr2, &arr1);
    Display(*arr3);
    free(arr3);

    return 0;
}
