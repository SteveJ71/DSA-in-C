# Sorted Insert — Linked List

Inserts a node into an already-sorted singly-linked list while maintaining sorted order.

## Files

| File | Purpose |
|------|---------|
| `linkedListInt.h` | Node struct and function prototypes |
| `linkedListInt.c` | `createNode`, `insertAtHead`, `insertAtTail`, `printList` |
| `sorted_insert_ll.c` | `sortedInsert` + `main` demo |

Note: `freeList` is present in `linkedListInt.c` but commented out (no `free` at end of `main`).

## Algorithm

`sortedInsert` walks the list to find the first node whose successor has a value ≥ the new node's value, then splices the new node in. Two special cases are handled upfront: empty list, and insert-before-head.

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o sorted_insert_ll sorted_insert_ll.c linkedListInt.c
./sorted_insert_ll
```
