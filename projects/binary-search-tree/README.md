# Binary Search Tree

A classic BST implementation with an interactive command-line tester.

## Features

- Insert at leaf (`TreeInsert`) — standard BST insertion
- Insert at root (`insertAtRoot`) — inserts then rotates new node to the root
- Delete (`TreeDelete`) — handles all cases via `joinTrees`
- Search (`TreeSearch`)
- Rotations — `rotateLeft`, `rotateRight` exposed for direct use
- Sideways text display (`showTree`)

> **Note:** `TreeHeight` is left unimplemented (returns -1) as a learning exercise.

## Files

| File | Purpose |
|------|---------|
| `include/BSTree.h` | BST ADT interface |
| `src/BSTree.c` | BST implementation |
| `src/treeLab.c` | Interactive tester |

## Compile & Run

```bash
make && ./treeLab
```

### Commands

| Command | Action |
|---------|--------|
| `i N` | Insert N (leaf insertion) |
| `I N` | Insert N at root |
| `d N` | Delete N |
| `s N` | Search for N |
| `r` | Rotate right around root |
| `l` | Rotate left around root |
| `n` | New (empty) tree |
| `q` | Quit |
