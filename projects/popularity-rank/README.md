# Popularity Rank

Ranks vertices in a **directed weighted graph** by a popularity score:

```
popularity(v) = inDegree(v) / outDegree(v)
```

Vertices with no outgoing edges use `0.5` as the denominator (treating dangling nodes as highly influential).

Results are sorted in descending order of popularity using insertion sort.

## Graph representation

Directed adjacency matrix (`src/WGraph.c`) — `insertEdge` stores the weight in one direction only. All edges are inserted with weight 1 in `main`.

## Compile & Run

```bash
make && ./popularity-rank
```

Enter the number of vertices, then edges one at a time as `(from, to)` pairs. Enter a non-integer to finish.

## Example

```
Enter the number of vertices: 4
Enter an edge (from): 0
Enter an edge (to): 1
Enter an edge (from): 0
Enter an edge (to): 2
Enter an edge (from): 1
Enter an edge (to): 3
Enter an edge (from): 2
Enter an edge (to): 3
Enter an edge (from): q
Done.

Popularity ranking:
3 4.0
1 0.5
2 0.5
0 0.0
```
