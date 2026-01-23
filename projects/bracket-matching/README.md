# Bracket Matching (Stack)

Checks whether brackets in a string are balanced.

Supported bracket pairs:
- `()`
- `{}`
- `[]`

## Demo

```sh
cc -Iinclude src/*.c -o bracket_demo
./bracket_demo "(({}))"
```

Or read from stdin:

```sh
./bracket_demo
# paste a line, press Enter
```

## Notes

- Non-bracket characters are ignored.
- Returns **balanced** only if every closer matches the most recent unmatched opener and no openers remain at the end.
