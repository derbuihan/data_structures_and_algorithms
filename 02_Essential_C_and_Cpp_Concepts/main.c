#include <stdio.h>

typedef struct Rectangle {
    int length;
    int breadth;
} Rectangle;

void init(Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(Rectangle r) {
    return r.length * r.breadth;
}

int perimeter(Rectangle r) {
    return 2 * (r.length + r.breadth);
}

void print_info(Rectangle r) {
    printf("Length: %d\n", r.length);
    printf("Breadth: %d\n", r.breadth);
    printf("Area: %d\n", area(r));
    printf("Perimeter: %d\n", perimeter(r));
    printf("\n");
}

int main() {
    Rectangle r;
    init(&r, 10, 5);

    print_info(r);

    r.length = 20;
    r.breadth = 10;

    print_info(r);

    return 0;
}
