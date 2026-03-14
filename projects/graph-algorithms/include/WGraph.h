// Weighted Graph ADT interface
#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices with an integer weight
typedef struct Edge {
   Vertex v;
   Vertex w;
   int    weight;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
int   adjacent(Graph, Vertex, Vertex);  // returns edge weight, 0 if no edge
void  showGraph(Graph);
void  freeGraph(Graph);
