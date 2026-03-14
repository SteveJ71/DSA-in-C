# Subset Sum

Recursive solution to the subset sum problem: given an array `A` of integers and a target `k`, does any subset of `A` sum to exactly `k`?

## Algorithm

At each step, either include the last element or exclude it:

```
subsetsum(A, n, k) =
  true                                   if k == 0
  false                                  if n == 0
  subsetsum(A, n-1, k-A[n-1])
    || subsetsum(A, n-1, k)              otherwise
```

This is O(2ⁿ) in the worst case.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o subset_sum subset_sum.c
echo "1 5 3 8 2" | ./subset_sum 11   # YES
echo "1 5 3 8 2" | ./subset_sum 7    # YES (5+2 or 3+2+... check)
echo "1 5 3 8 2" | ./subset_sum 100  # NO
```
