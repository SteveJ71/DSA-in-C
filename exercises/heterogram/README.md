# Heterogram

Checks whether a word or phrase is a **heterogram** — a string where no letter appears more than once (spaces are ignored).

Uses a brute-force O(n²) double-loop to compare every pair of characters.

## Examples

- `"the quick brown fox"` → heterogram (no repeated letters, ignoring spaces)
- `"hello"` → not a heterogram (`l` appears twice)

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o heterogram heterogram.c
./heterogram
```
