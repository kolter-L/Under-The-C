#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

// Initialize vector
void initVector(Vector *v, int capacity) {
    v->data = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

// Add element (resize if needed)
void push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

// Print elements
void printVector(Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

// Free memory
void freeVector(Vector *v) {
    free(v->data);
}

int main() {
    Vector v;
    initVector(&v, 2);

    char input = 'y';

    while (input != 'q') {
        printf("Enter a number to add to the vector or 'q' to quit: ");
        scanf(" %c", &input);
        if (input != 'q') {
            push_back(&v, input - '0');
            printVector(&v);
        }
    }

    push_back(&v, 10);
    push_back(&v, 20);
    push_back(&v, 30);  // Triggers resize
    push_back(&v, 40);

    printVector(&v);  // Output: 10 20 30 40

    freeVector(&v);
    return 0;
}
