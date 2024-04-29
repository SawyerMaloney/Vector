#include <stdlib.h>
#include <stdio.h>

// first iteration: assume that we are storing an integer

typedef struct {
    int * array;
    int size;
} vector;

vector make_vec() {
    vector vec;
    vec.size = 0;
    return vec;
}

int main() {
    printf("Hello, World\n");
    vector vec = make_vec();
    printf("size of vec: %d\n", vec.size);
    return 1;
}
