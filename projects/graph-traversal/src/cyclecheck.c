// Determine if an undirected graph contains a cycle
#include <stdio.h>
#include <stdlib.h>
#include "../include/Graph.h"

#define MAX_NODES 1000

bool visited[MAX_NODES];

bool dfsCycleCheck(Graph g, Vertex v, Vertex parent) {
    visited[v] = true;
    for (Vertex w = 0; w < numOfVertices(g); w++) {
        if (adjacent(g, v, w)) {
            if (!visited[w]) {
                if (dfsCycleCheck(g, w, v))
                    return true;
            }
            else if (w != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(Graph g) {
    for (Vertex v = 0; v < numOfVertices(g); v++)
        visited[v] = false;
    for (Vertex v = 0; v < numOfVertices(g); v++) {
        if (!visited[v]) {
            if (dfsCycleCheck(g, v, -1))
                return true;
        }
    }
    return false;
}

int main(void) {
    int n;
    int input[2];

    printf("Enter the number of vertices: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    Graph g = newGraph(n);
    Edge e;

    while (1) {
        printf("Enter an edge (from): ");
        if (scanf("%d", &input[0]) != 1) {
            while (getchar() != '\n');
            break;
        }

        printf("Enter an edge (to): ");
        if (scanf("%d", &input[1]) != 1) {
            while (getchar() != '\n');
            break;
        }

        e.v = input[0];
        e.w = input[1];
        insertEdge(g, e);
    }

    printf("Done.\n");

    if (hasCycle(g))
        printf("The graph has a cycle.\n");
    else
        printf("The graph is acyclic.\n");

    freeGraph(g);
    return 0;
}
