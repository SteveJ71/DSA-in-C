# Balanced BST

Extended BST with multiple insertion strategies, plus a Red-Black Tree skeleton.

## BST — Extended (`BST.h` / `BST.c`)

Builds on the basic BST with additional insertion strategies and proper height tracking:

| Insertion strategy | Function | Description |
|-------------------|----------|-------------|
| Leaf | `TreeInsert` | Standard BST |
| Root | `insertAtRoot` | Rotates new node up to root |
| Random | `insertRandom` | 40% chance of root insertion, 60% leaf |
| AVL | `insertAVL` | Rebalances via rotations to maintain height balance |
| Splay | `insertSplay` | Splays new node towards root (zig-zig / zig-zag) |

Also includes `TreeHeight` (implemented), horizontal level-order `showTree` (uses queue), and `rebalance` (stub — not yet implemented).

## Red-Black Tree (`RBTree.h` / `RBTree.c`)

Sideways display with red nodes printed in terminal colour.

> **Note:** `TreeInsert` is not yet implemented — returns a fixed 3-node test tree as a placeholder. `rebalance` in `BST.c` is also a stub.

## Files

| File | Purpose |
|------|---------|
| `include/BST.h` | Extended BST interface |
| `include/RBTree.h` | Red-Black Tree interface |
| `include/queue.h` | Generic `void*` queue interface |
| `src/BST.c` | Extended BST implementation |
| `src/RBTree.c` | Red-Black Tree implementation |
| `src/RBTester.c` | RBTree command-line tester |
| `src/treeLab.c` | Interactive BST tester |
| `src/queue.c` | Generic queue (stores `void*`, used by `showTree`) |

## Compile & Run

```bash
make           # builds both treeLab and rbt
make treeLab   # interactive BST tester
make rbt       # red-black tree tester
```

### treeLab commands

| Command | Action |
|---------|--------|
| `i N` | Insert N (leaf) |
| `I N` | Insert N at root |
| `R N` | Insert N at random |
| `a N` | Insert N (AVL) |
| `z N` | Insert N (Splay) |
| `d N` | Delete N |
| `s N` | Search for N |
| `r` / `l` | Rotate right / left |
| `b` | Rebalance (stub) |
| `n` | New empty tree |
| `q` | Quit |

### rbt usage

```bash
./rbt 5 3 7 1 4
```
Inserts values from command-line arguments and displays the resulting tree.
