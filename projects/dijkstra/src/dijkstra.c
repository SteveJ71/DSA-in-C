// Dijkstra's algorithm using a priority queue ADO

#include <stdio.h>
#include <stdbool.h>
#include "../include/PQueue.h"

#define VERY_HIGH_VALUE 999999

// Print the shortest paths and their distances from source to all vertices
void printShortestPaths(int dist[], int pred[], int nV, Vertex source) {
    for (int t = 0; t < nV; t++) {
        if (dist[t] == VERY_HIGH_VALUE) {
            printf("%d: no path\n", t);
        }
        else {
            printf("%d: distance = %d, shortest path: ", t, dist[t]);

            int path[MAX_NODES];
            int pathLength = 0;
            int current = t;
            while (current != source) {
                if (pred[current] == -1) {
                    break;
                }
                path[pathLength++] = current;
                current = pred[current];
            }
            path[pathLength++] = source;

            for (int i = pathLength - 1; i >= 0; i--) {
                printf("%d", path[i]);
                if (i > 0) {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
}

// Run Dijkstra's single-source shortest path algorithm
void dijkstraSSSP(Graph g, Vertex source) {
    int  dist[MAX_NODES];
    int  pred[MAX_NODES];
    bool vSet[MAX_NODES];
    int nV = numOfVertices(g);

    // Initialise priority queue, dist, pred and vertex set arrays
    PQueueInit();
    for (int s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;

    // Main loop of Dijkstra's algorithm
    while (!PQueueIsEmpty()) {
        Vertex current = leavePQueue(dist);
        if (!vSet[current]) continue;
        vSet[current] = false;

        for (int t = 0; t < nV; t++) {
            int weight = adjacent(g, current, t);
            if (weight > 0 && dist[current] + weight < dist[t]) {
                dist[t] = dist[current] + weight;
                pred[t] = current;
            }
        }
    }

    printShortestPaths(dist, pred, nV, source);
}

// Reverse the direction of an edge
void reverseEdge(Edge *e) {
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void) {
    Edge e;
    int  n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);

    // Read edges and insert them into the graph
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e);               // add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}
