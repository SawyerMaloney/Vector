#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_SIZE 10
#define RESIZE_RATE 2


// first iteration: assume that we are storing an integer
// vector struct that will be the basis for the resizing array
typedef struct {
    int * array;
    int size;
    int capacity;
} _vector;

typedef _vector * vector;

// forward declarations
void grow(vector vec);

// malloc wrapper
void * malloc_checked(int size) {
    void * p = malloc(size);
    if (p == 0) {
        printf("Out of memory\n");
        exit(1);
    }
    return p;
}

// initialize empty vector with DEFAULT_SIZE capacity
vector make_vec() {
    vector vec = (vector) malloc_checked(sizeof(*vec));
    vec->array = (int *) malloc_checked(sizeof(int) * DEFAULT_SIZE);
    vec->size = 0;
    vec->capacity = DEFAULT_SIZE;
    return vec;
}

// add 'a' to the vector
void add(vector vec, int a) {
     if (vec->size >= vec->capacity) {
         // need to resize
         grow(vec);
     }
     vec->array[vec->size++] = a;
}

// remove last element of the array
int pop(vector vec) {
    int removed_element = vec->array[--vec->size];
    vec->array[vec->size] = 0; // may want to change this to be a removed element? By using a struct
    // TODO resize down for efficiency
    return removed_element;    
}

void grow(vector vec) {
    int new_capacity = vec->capacity * RESIZE_RATE;
    int * new_array = malloc_checked(sizeof(int) * new_capacity);
    // copy everything over
    for(int i = 0; i < vec->size; i++) {
        new_array[i] = vec->array[i];
    }
    free(vec->array);
    vec->array = new_array;
    vec->capacity = new_capacity;
}

int main() {
    printf("Hello, World\n");
    vector vec = make_vec();
    printf("size of vec: %d\n", vec->size);
    for (int i = 0; i < 100; i++) {
        add(vec, i);
    }
    printf("new size of vec: %d\n", vec->size);
    return 1;
}
