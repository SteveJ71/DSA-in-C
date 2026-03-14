# Randword

Generates a random word of lowercase letters given a length and a seed.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o randword randword.c
./randword 8 42
```

Produces the same word each time for the same seed — useful for testing other programs that process strings.
