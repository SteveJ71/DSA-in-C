# Pair With Sum

Brute-force O(n²) search for any pair of elements in an array that sum to a target value `v`.

Hardcoded test: `A = {1, 9, 20, 40, 60, 80}`, `v = 82` → finds the pair (2, 80) at positions A[1] and A[5].

Prints every pair checked, then reports whether a match was found.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o pair_with_sum pair_with_sum.c
./pair_with_sum
```
