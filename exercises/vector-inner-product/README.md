# Vector Inner Product

Computes the **dot product** (inner product) of two vectors of equal length using dynamically allocated float arrays.

The dot product of vectors **a** and **b** is: `a·b = Σ aᵢ × bᵢ`

Demonstrates `malloc`/`free` for runtime-sized arrays.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o vector_inner_product vector_inner_product.c
./vector_inner_product
```

Example session (n=3, a=[1,2,3], b=[4,5,6]):
```
Enter a number: 3
Enter a value: 1
Enter a value: 2
Enter a value: 3
Enter a value: 4
Enter a value: 5
Enter a value: 6
Inner product is 32.000000
```
