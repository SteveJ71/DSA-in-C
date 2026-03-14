# Prefix Averages

Two implementations of prefix averages with a timing comparison, demonstrating the practical difference between O(n²) and O(n).

Given array `X[0..n-1]`, `A[i] = (X[0] + X[1] + ... + X[i]) / (i+1)`.

| Function | Approach | Complexity |
|----------|----------|-----------|
| `prefixAverages1` | Recomputes the running sum from scratch for each `i` | O(n²) |
| `prefixAverages2` | Maintains a running sum, adding one element per step | O(n) |

Both are timed for n = 1000, 10000, and 100000.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o prefix_averages prefix_averages.c
./prefix_averages
```
