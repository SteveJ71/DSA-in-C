# Make 10 Game

Given 4 digits (as seen on a train number), find all arithmetic expressions using the operators `+`, `-`, `*`, `/`, `^` that evaluate to 10.

## Approach

1. **Heap's Algorithm** generates all 24 permutations of the 4 digits
2. For each permutation, all 5³ = 125 operator combinations are tried
3. For each operator combination, all 5 parenthesisation patterns are tested:
   - `(a·b)·(c·d)`
   - `(a·(b·c))·d`
   - `a·((b·c)·d)`
   - `((a·b)·c)·d`
   - `a·(b·(c·d))`

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o make10_game make10_game.c -lm
./make10_game 5341
```

Pass the 4-digit train number as a command line argument. Each character is treated as a separate digit.

## Example output

```
Make 10 Game

Train Number: 5341

Solution found: (5-3+4)*1... (etc)
finished!!!!
```

## Notes

- Duplicate solutions may be printed — the same expression can appear multiple times across different permutations
- Division by zero is not guarded against; results involving it may print as `inf` or `nan`
