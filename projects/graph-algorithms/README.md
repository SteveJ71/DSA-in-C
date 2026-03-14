# Graph Algorithms

Four classic weighted-graph algorithms, each built on a shared **Weighted Graph ADT** backed by an adjacency matrix.

The adjacency matrix stores edge weights directly (0 = no edge), so `adjacent(g, v, w)` returns the weight rather than a boolean — making it a natural fit for cost- and capacity-based algorithms.

## Algorithms

| File | Algorithm | Problem solved |
|------|-----------|---------------|
| `src/kruskal.c` | Kruskal's MST | Minimum spanning tree — cheapest set of edges connecting all vertices |
| `src/floyd.c` | Floyd-Warshall | All-pairs shortest paths — shortest distance between every pair of vertices |
| `src/warshall.c` | Warshall's | Transitive closure — which vertices are reachable from which |
| `src/edmonds_karp.c` | Edmonds-Karp | Maximum flow — maximum throughput from source to sink |

## Graph Representation

| File | Purpose |
|------|---------|
| `include/WGraph.h` | Weighted Graph ADT interface |
| `src/wgraph.c` | Adjacency matrix implementation (stores weights, 0 = no edge) |
| `include/queue.h` / `src/queue.c` | FIFO queue (used by Edmonds-Karp BFS) |

## Compile & Run

```bash
make              # builds all four programs
make clean        # removes compiled binaries
```

To build and run a specific program:
```bash
make kruskal      && ./kruskal
make floyd        && ./floyd
make warshall     && ./warshall
make edmonds-karp && ./edmonds-karp
```

## Notes

- **Warshall** is self-contained (no graph ADT — works directly on a 2D array).
- **Kruskal** expects edges pre-sorted by weight (the demo input is already sorted).
- **Floyd-Warshall** and **Edmonds-Karp** use `VERY_HIGH_VALUE = 999999` as a stand-in for infinity.
