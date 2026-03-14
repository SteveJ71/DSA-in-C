# Graph Traversal

Undirected graph ADT with two interchangeable representations, plus five classic graph algorithms built on top.

## Graph Representations

| File | Representation | Notes |
|------|---------------|-------|
| `src/graph_adjlist.c` | Adjacency list | Array of linked lists — efficient for sparse graphs |
| `src/graph_edgelist.c` | Array of edges | Simple flat array — easier to reason about, less efficient |

Both implement the same `Graph.h` interface, so any algorithm can compile against either.

## Algorithms

| File | Algorithm | Approach |
|------|-----------|---------|
| `src/dfs.c` | Depth-First Search | Recursive — finds a path between two vertices |
| `src/bfs.c` | Breadth-First Search | Queue-based — finds the shortest path |
| `src/components.c` | Connected Components | DFS-based labelling of each component |
| `src/euler.c` | Euler Path check | Degree parity check (necessary condition) |
| `src/hamiltonian.c` | Hamiltonian Path check | Backtracking search |
| `src/cyclecheck.c` | Cycle detection | DFS-based — works on disconnected graphs |
| `src/graphtester.c` | ADT tester | Tests insert/remove/show on both representations |

## Compile & Run

```bash
make          # builds all programs (uses adjacency list by default)
make clean    # removes compiled binaries
```

To build a specific program:
```bash
make dfs && ./dfs
make bfs && ./bfs
make euler && ./euler
```

To test with the edge-list representation instead:
```bash
make graphtester-edgelist && ./graphtester-edgelist
```

## Supporting ADTs

| File | Purpose |
|------|---------|
| `include/list.h` / `src/list.c` | Singly-linked list (used by adjacency list graph) |
| `include/queue.h` / `src/queue.c` | FIFO queue (used by BFS) |
