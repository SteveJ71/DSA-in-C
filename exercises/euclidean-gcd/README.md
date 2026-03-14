# Euclidean GCD

Two implementations of the **Greatest Common Divisor** algorithm.

| File | Approach |
|------|----------|
| `euclid_recursive.c` | Recursive — uses modulo (`m % n`) |
| `gcd_subtraction.c` | Iterative — uses repeated subtraction |

Both produce the same result. The recursive version (Euclid's algorithm) is more efficient for large numbers because modulo converges faster than repeated subtraction.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o euclid euclid_recursive.c
./euclid

gcc -Wall -Werror -std=c11 -O0 -g -o gcd gcd_subtraction.c
./gcd
```

Both print `6` (the GCD of 30 and 18).
