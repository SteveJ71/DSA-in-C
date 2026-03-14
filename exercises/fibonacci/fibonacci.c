// Fibonacci: naive recursive vs iterative implementations with timing comparison

#include <stdio.h>
#include <time.h>

#define MAX 50

// My first attempt. Very slow.
// Each call to fibonacci results in 2 more recursive calls.
// This leads to exponential growth in the number of function calls.
//
// For the recursive fibonacci function, when you have n = 4, the function calls will unfold as follows:
//
// fibonacci(4) is called.
// This leads to calls to fibonacci(3) and fibonacci(2).
// fibonacci(3) is called.
// This leads to calls to fibonacci(2) and fibonacci(1).
// fibonacci(2) (from the call in step 2) is called.
// This leads to calls to fibonacci(1) and fibonacci(0).
// fibonacci(2) (from the call in step 1) is called.
// This leads to calls to fibonacci(1) and fibonacci(0).
// In total, the fibonacci(4) call results in the following function calls:
//
// 1 call to fibonacci(4)
// 1 call to fibonacci(3)
// 2 calls to fibonacci(2) (one from fibonacci(4) and one from fibonacci(3))
// 3 calls to fibonacci(1) (one from fibonacci(3) and two from the two fibonacci(2) calls)
// 2 calls to fibonacci(0) (both from the two fibonacci(2) calls)
// So, for n = 4, there are a total of 9 function calls. This illustrates how quickly the number of calls
// can grow with recursion, even for relatively small values of n.

int fibonacci(int n) {

    int result = 0;

    if (n < 3) {
        result = 1;
    }

    else {
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return result;

}

// Massive difference in time.
// Second function is much faster.
// Fib[50] = -298632863, Time: 73.679000 seconds
// FibV2[50] = -298632863, Time: 0.000000 seconds
// It moves forward through i = 0 to n and avoids all the recursion.

int fibonacciV2(int n) {

    int i;
    int fib[MAX] = { 1, 1 };

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n-1];
}

int main(void) {

    int fib, fib2;
    clock_t start, end;
    double cpu_time_used_fib, cpu_time_used_fib2;

    // Time fibonacci function
    start = clock();
    fib = fibonacci(MAX);
    end = clock();
    cpu_time_used_fib = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fib[%d] = %d, Time: %f seconds\n", MAX, fib, cpu_time_used_fib);

    // Time fibonacciV2 function
    start = clock();
    fib2 = fibonacciV2(MAX);
    end = clock();
    cpu_time_used_fib2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("FibV2[%d] = %d, Time: %f seconds\n", MAX, fib2, cpu_time_used_fib2);

    return 0;

}
