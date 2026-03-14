// Pointer examples: basic dereferencing, pass-by-pointer, pointer arithmetic,
// double pointers, and 2D dynamic arrays

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void func(int* a) {
    *a += 1;
    printf("Inside func, incremented value: %d\n", *a);
}



void Example1() {
    int a = 5;
    int b = 123;
    int* pa = &a;
    int* pb = &b;
    printf("Initial values -> a: %d, b: %d\n", a, b);

    *pa = 6;
    printf("a changed to: %d\n", a);

    *pb = 234;
    printf("b changed to: %d\n", b);

    int c = *pa;
    *pa = *pb;
    *pb = c;

    printf("After swapping -> a: %d, b: %d\n", a, b);

    pa = pb;
    *pa = 345;
    printf("After redirecting pa to pb and modifying value -> a: %d, b: %d\n", a, b);
}

void Example2() {
    int x = 6;
    int* px = &x;
    printf("Before func -> x: %d\n", x);

    func(px);
    printf("After func -> x: %d\n", x);
}

void Example3() {
    int* ptr1, * ptr2;
    int i = 10, j = 20;
    printf("Initial values -> i: %d, j: %d\n", i, j);

    ptr1 = &i;
    ptr2 = &j;

    *ptr1 = *ptr1 + *ptr2;
    printf("After adding j to i -> i: %d\n", i);

    ptr2 = ptr1;
    *ptr2 = 2 * (*ptr2);
    printf("After setting ptr2 to ptr1 and doubling -> i: %d, j: %d\n", i, j);

    printf("Final Val = %d\n", *ptr1 + *ptr2);  // Since ptr1 and ptr2 are the same, this doubles i.
}

void func2(int** a) {
    *a = malloc(sizeof(int));
    assert(*a != NULL);  // Ensures that memory allocation was successful
    printf("Memory allocated for pointer, Address of a: %p, Address stored in a: %p, Type of a: pointer to int*\n", (void*)&a, (void*)*a);
}

void Example4() {
    int* p = NULL;
    printf("Initial state of p: Name: p, Address of p: %p, Value of p: %p, Type: int*\n", (void*)&p, (void*)p);

    func2(&p);
    printf("After func2 - Address of p: %p, Value pointed by p (newly allocated memory): %p, Type: int*\n", (void*)&p, (void*)p);

    *p = 6;
    printf("After setting *p - p points to Address: %p, Value at *p: %d, Type of *p: int\n", (void*)p, *p);

    free(p);
    printf("Memory freed for pointer p. Address of p remains: %p, Value of p now becomes: %p (dangling pointer)\n", (void*)&p, (void*)p);

    // Resetting p to null to avoid dangling reference
    p = NULL;
    printf("Pointer p reset to NULL, Address of p: %p, Value of p: %p\n", (void*)&p, (void*)p);
}


void Example5() {
    int m = 8; // number of rows
    int n = 4; // number of columns

    // Allocate memory for m pointers to rows of floats
    float** matrix = malloc(m * sizeof(float*));
    assert(matrix != NULL);  // Ensure memory allocation was successful
    printf("Allocated memory for matrix (array of pointers): Address of matrix = %p\n", (void*)matrix);

    // Allocate memory for the elements in each row and display addresses
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(float)); //matrix[i] are all pointers
        assert(matrix[i] != NULL);  // Ensure memory allocation for each row was successful
        printf("Row %d allocated at %p (stored in matrix[%d] = %p)\n", i, (void*)matrix[i], i, (void*)&matrix[i]);
    }

    // Optionally, initialize and display the matrix content

    //The compiler understands matrix[i][j] as accessing an offset of j from the pointer matrix[i], based on the size of float.

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;  // Simple initialization for demonstration: fill with sequential numbers
            printf("matrix[%d][%d] = %.1f (Address = %p)\n", i, j, matrix[i][j], (void*)&matrix[i][j]);
        }
    }

    // Clean up: Free all allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);  // Free each row
    }
    free(matrix);  // Free the array of pointers
}


int main(void) {
    printf("Running Example1...\n");
    Example1();
    printf("\nRunning Example2...\n");
    Example2();
    printf("\nRunning Example3...\n");
    Example3();
    printf("\nRunning Example4...\n");
    Example4();
    printf("\nRunning Example5...\n");
    Example5();

    return 0;
}
