# Fibonacci

Two implementations of Fibonacci with timing comparison.

## Implementations

| Function | Approach | Complexity |
|----------|----------|-----------|
| `fibonacci(n)` | Naive recursion — each call spawns two more | O(2ⁿ) |
| `fibonacciV2(n)` | Iterative array fill | O(n) |

`main` times both for `n = 50`. The difference is dramatic — the recursive version takes ~74 seconds while the iterative version is effectively instant. Both produce the same (overflowed) result because `int` wraps around for large Fibonacci numbers.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o fibonacci fibonacci.c
./fibonacci
```

> **Note:** Do not run this under Valgrind. The recursive `fibonacci(50)` makes ~2⁵⁰ calls and takes ~74 seconds natively — Valgrind adds 20x overhead, making it hang for ~25 minutes. This program also uses no heap allocation, so there is nothing for Valgrind to check.
