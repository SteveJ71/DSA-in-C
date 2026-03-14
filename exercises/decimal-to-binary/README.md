# Decimal to Binary

Converts a decimal integer to binary by repeatedly extracting the least significant bit (`n % 2`) and pushing it onto a stack. Popping the stack reverses the bits into the correct order.

Demonstrates a practical use of a stack (LIFO reversal) with a heap-allocated linked-list Stack ADT.

## Files

| File | Purpose |
|------|---------|
| `stack.h` | Stack ADT interface |
| `stack.c` | Stack ADT implementation (linked list, heap-allocated) |
| `binary.c` | Decimal-to-binary conversion using the stack |

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o binary binary.c stack.c
./binary 42
```

Output: `101010`

## Memory Check

The stack ADT uses `malloc` for both the stack struct and each node. `dropStack` frees all nodes then the stack itself.

```bash
valgrind -s --leak-check=full --show-leak-kinds=all ./binary 42
```
