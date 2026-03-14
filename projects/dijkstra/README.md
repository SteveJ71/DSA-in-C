# Dijkstra's Algorithm

Single-Source Shortest Path (SSSP) using a **Priority Queue ADO**.

Given a weighted graph and a source vertex, finds the shortest path from the source to every other vertex.

## How it works

1. All vertices are added to the priority queue with distance ∞ (source = 0)
2. Each iteration dequeues the unvisited vertex with the lowest known distance
3. Its neighbours are relaxed — if a shorter path is found, `dist[t]` and `pred[t]` are updated
4. The predecessor array `pred[]` is used to reconstruct each path

## Priority Queue

The `PQueue` is implemented as a **static array ADO** (not a heap). `leavePQueue` does a linear scan to find the minimum — O(n) per dequeue vs O(log n) for a binary heap, but simpler to understand.

## Graph Representation

`WGraph` is a **directed** adjacency matrix storing edge weights (0 = no edge). The `main` function inserts each edge in both directions via `reverseEdge` to model undirected graphs.

## Files

| File | Purpose |
|------|---------|
| `include/WGraph.h` | Weighted directed graph interface |
| `include/PQueue.h` | Priority queue ADO interface |
| `src/WGraph.c` | Adjacency matrix implementation |
| `src/PQueue.c` | Priority queue implementation (linear-scan array) |
| `src/dijkstra.c` | Dijkstra's SSSP + path printing + interactive input |

## Compile & Run

```bash
make && ./dijkstra
```

### Example session

```
Enter the number of vertices: 5
Enter the source node: 0
Enter an edge (from): 0
Enter an edge (to): 1
Enter the weight: 10
Enter an edge (from): 0
Enter an edge (to): 2
Enter the weight: 3
Enter an edge (from): 2
Enter an edge (to): 1
Enter the weight: 4
Enter an edge (from): 1
Enter an edge (to): 3
Enter the weight: 2
Enter an edge (from): ^D
Done.
0: distance = 0, shortest path: 0
1: distance = 7, shortest path: 0-2-1
2: distance = 3, shortest path: 0-2
3: distance = 9, shortest path: 0-2-1-3
4: no path
```

Press `Ctrl+D` (Linux/Mac) or `Ctrl+Z` (Windows) to end edge input.

## Memory Check

`WGraph` uses `malloc`/`calloc` for the graph struct and each row of the adjacency matrix. `freeGraph` frees all of these. The `PQueue` is a static array — no heap allocation.

Since the program is interactive, pipe input in using a here-document:

```bash
valgrind -s --leak-check=full --show-leak-kinds=all ./dijkstra << 'EOF'
5
0
0 1 10
0 2 3
2 1 4
1 3 2
EOF
```
