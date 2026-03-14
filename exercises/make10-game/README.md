# Make 10 Game

Given 4 digits (as seen on a train number), find all arithmetic expressions using the operators `+`, `-`, `*`, `/`, `^` that evaluate to 10.

## Approach

1. **Heap's Algorithm** generates all 24 permutations of the 4 digits
2. For each permutation, all 5³ = 125 operator combinations are tried
3. For each operator combination, four parenthesisation patterns are tested:
   - `(ab)·(cd)`
   - `(a·(bc))·d`
   - `a·((bc)·d)`
   - `((ab)·c)·d`

## Known issues

- `hasSolution` is declared `void` but ends with `return false` (bug preserved)
- The "3 zero case" check returns a message but does not `return` early, so processing continues anyway

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o make10_game make10_game.c -lm
./make10_game
```

Edit `input[4]` in `main` to test different digit combinations.
