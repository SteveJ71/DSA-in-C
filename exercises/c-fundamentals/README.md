# C Fundamentals

Small standalone programs exploring core C concepts.

## Files

| File | Topic | Notes |
|------|-------|-------|
| `pointers.c` | Pointer basics | Dereferencing, pass-by-pointer, double pointers (`int**`), 2D dynamic arrays |
| `structs_on_heap.c` | Heap allocation | `malloc` a linked list node, access with `->` |
| `memory_management.c` | Insertion sort (incomplete) | Bug preserved: missing `array[j+1] = element` after inner loop |
| `cpuzzles.c` | Array reversal (Puzzle D31) | Bug preserved: `fillArrayInOrder` called with arguments in wrong order; uses `system("PAUSE")` |
| `llcreate.c` | Linked list creation | Builds a singly-linked list from stdin input; appends to tail; properly frees on exit |
| `memerrors.c` | Memory bugs exercise | 8 functions (`f1`–`f8`), each with a corrected common memory mistake (unchecked malloc, memory leak, buffer overflow, double free, invalid free, uninitialised read, etc.) |

## Compile & Run

Each file is self-contained:

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o pointers pointers.c
./pointers

gcc -Wall -Werror -std=c11 -O0 -g -o structs_on_heap structs_on_heap.c
./structs_on_heap

gcc -Wall -Werror -std=c11 -O0 -g -o memory_management memory_management.c
./memory_management

gcc -Wall -Werror -std=c11 -O0 -g -o cpuzzles cpuzzles.c
./cpuzzles

gcc -Wall -Werror -std=c11 -O0 -g -o llcreate llcreate.c
./llcreate

gcc -Wall -Werror -std=c11 -O0 -g -o memerrors memerrors.c
./memerrors
```
