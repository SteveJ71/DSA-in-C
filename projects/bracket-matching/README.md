# Bracket Matching (Stack)

Checks whether brackets in a string are balanced.

Supported bracket pairs:
- `()`
- `{}`
- `[]`

## Demo

This program reads bracket strings from a text file named `text.txt`,
processing one line at a time.

### Steps

1. Create a file called `text.txt` in this directory.
2. Add one bracket string per line, for example:

(({}))
([)]
([]{})

3. Build and run the program:

```bash
gcc -Wall -Werror -std=c11 -O0 -g -I include -o bracket_matching src/main.c src/stack.c src/bracket_matching.c
./bracket_matching
```

## Notes

- Non-bracket characters are ignored.
- Returns **balanced** only if every closer matches the most recent unmatched opener and no openers remain at the end.
