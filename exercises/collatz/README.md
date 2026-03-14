# Collatz Sequence

Two versions of the same algorithm — the **Collatz conjecture** (also called the 3n+1 problem).

Starting from any positive integer n, repeatedly apply:
- if n is even → n = n / 2
- if n is odd  → n = 3n + 1

The conjecture states this always eventually reaches 1.

| File | Input method |
|------|-------------|
| `collatz_interactive.c` | Prompts user via stdin |
| `collatz_cmdline.c` | Reads argument from command line |

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o collatz_i collatz_interactive.c
./collatz_i

gcc -Wall -Werror -std=c11 -O0 -g -o collatz_c collatz_cmdline.c
./collatz_c 6
```

Output for n=6: `6 3 10 5 16 8 4 2 1` (one per line)
