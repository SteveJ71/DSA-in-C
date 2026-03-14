/**
 * Each of the functions f1() to f8() below contains
 * a common memory mistake that results in either
 * a run-time error or "undefined behaviour".
 *
 * First identify each mistake, then correct it.  Fixing the
 * code will require adding, modifying, moving, or removing
 * one line of code from each of the 8 functions.
 *
 * Once corrected, the code should compile without warnings,
 * run without error, and not leak any memory.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/* swap the values of two integer variables */
void swap(int *p, int *q) {
   int temp = *p;
   *p = *q;
   *q = temp;
}

/* copy the values of integer array a[] to b[] */
void copy(int a[], int b[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      b[i] = a[i];
   }
}

/* print all the values of a dynamic integer array */
void print(int *b, int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", b[i]);
   }
   putchar('\n');
   free(b);
}

/* DO NOT MODIFY ANY OF THE CODE ABOVE THIS LINE */

void f1(void) {
   int ar[3] = {10, 20, 30};
   int *cp = malloc(3 * sizeof(int));

   // Unckecked malloc error - following line added.
   assert(cp != NULL);

   copy(ar, cp, 3);
   print(cp, 3);

}

void f2(void) {
   int a = 9024;
   int *c = malloc(sizeof(int));
   assert(c != NULL);
   *c = 2024;
   swap(&a, c);
   printf("%d %d\n", a, *c);

   // memory leak. f2 is not freeing the memory
   free(c);

}

void f3(void) {
   int ar[2] = {90, 24};
   int *cp = malloc(2 * sizeof(int));
   assert(cp != NULL);
   copy(ar, cp, 2);

   // Think the following is a buffer overflow
   // and not an unitialized read.
   // A buffer overflow (or overrun) is a situation in which a program uses
   // locations adjacent to a buffer (i.e., beyond one or both of the boundaries of a buffer).
   // This is what happens below cp[2] is a location adjacent to the buffer.

   //printf("%d %d\n", cp[1], cp[2]);

   // Corrected line.
   printf("%d %d\n", cp[0], cp[1]);

   free(cp);
}

void f4(void) {
   int ar[3] = {90, 24, 42};
   int *cp = malloc(3 * sizeof(int));
   assert(cp != NULL);
   copy(ar, cp, 3);
   print(cp, 3);

   // following line is a double free error
   // cp is freed in the print function.
   //free(cp);
}

void f5(void) {
   int ar[2] = {90, 24};
   int *cp = malloc(2 * sizeof(int));
   assert(cp != NULL);
   copy(ar, cp, 2);
   print(cp, 2);

   // following line is invalid free error
   // as was not allocated to the heap.
   //free(ar);
}

void f6(void) {
   int ar[3] = {2, 1, 0};
   int *cp = malloc(3 * sizeof(int));

   // the following line copies only the first
   // 2 elements of ar to cp but later then
   // prints all three elements of cp.
   // This leads to an unitialised read from
   // addressable memory.

   //copy(ar, cp, 2);

   // correct line is:
   copy(ar, cp, 3);

   print(cp, 3);
}

void f7(void) {

   int *cp = malloc(sizeof(int));
   assert(cp != NULL);
   *cp = 90;
   int a[1] = {24};

   swap(&a[0], cp);
   printf("%d %d\n", a[0], *cp);

   // memory is not cleared so memory leak
   // add the following line
   free(cp);
}

void f8(void) {
   int a = 90;

   // no memory allocated error.
   //int *c;

   // add following line
   int* c= malloc(sizeof(int));

   assert(c != NULL);
   *c = 24;
   swap(&a, c);
   printf("%d %d\n", a, *c);
   free(c);
}


int main(void) {


   printf("f1: ");
   f1();
   printf("f2: ");
   f2();
   printf("f3: ");
   f3();
   printf("f4: ");
   f4();
   printf("f5: ");
   f5();
   printf("f6: ");
   f6();
   printf("f7: ");
   f7();
   printf("f8: ");
   f8();


   return 0;
}
