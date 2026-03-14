# Time Complexity

Counts individual primitive operations in a nested loop to illustrate O(n²) complexity analysis.

Tracks three separate counters:
- **Outer loop** — condition checks in the outer `for` loop
- **Inner loop** — condition checks in the inner `for` loop (including the final failing check)
- **Assignments** — the assignment and addition inside the loop body

For input `n`, the total primitive operation count is approximately `3n² + 3n + 1`.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o time_complexity time_complexity.c
./time_complexity
```
