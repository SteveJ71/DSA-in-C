# Insertion Sort

A simple O(n²) sorting algorithm. Works by building a sorted subarray one element at a time — each new element is inserted into its correct position by shifting larger elements right.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o insertion_sort insertion_sort.c
./insertion_sort
```

Output (sorted from `{ 3, 6, 5, 2, 4, 1 }`):

```
1
2
3
4
5
6
```
