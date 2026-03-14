// Algorithm to rank the nodes in a directed graph according to popularity.
// Popularity of a vertex v = inDegree(v) / outDegree(v).
// Vertices with no outgoing edges use 0.5 as denominator.

#include <stdio.h>
#include <stdlib.h>
#include "../include/WGraph.h"

typedef struct {
	int vertex;
	double popularity;
} Popularity;


// function to calculate the out degree of vertex v
int outDegree(Graph g, int v) {

	int count = 0;
	int nV = numOfVertices(g);

    for (int w = 0; w < nV; w++) {
		if (adjacent(g, v, w) > 0) { //edge found
			count++;
		}
	}

	return count;
}

// function to calculate the in degree of vertex v
int inDegree(Graph g, int v) {

	int count = 0;
	int nV = numOfVertices(g);

	for (int w = 0; w < nV; w++) {
		if (adjacent(g, w, v) > 0) { //edge found
			count++;
		}
	}

	return count;
}

// Function to sort an array of Popularity structures
// in descending order of popularity
void insertionSort(Popularity array[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		Popularity element = array[i];
		int j = i - 1;
		while (j >= 0 && array[j].popularity <  element.popularity) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = element;
	}
}


int main(void) {

	int nV;
	int input[2];

	printf("Enter the number of vertices: ");
	if (scanf("%d", &nV) != 1) {
		return 1;
	}

	Graph g = newGraph(nV);
	Edge e;

	// Input edges
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
		e.weight = 1;
		insertEdge(g, e);

	}

	printf("Done.\n\n");

	// Allocate memory for the popularity array
	Popularity* popularityArray = malloc(nV * sizeof(Popularity));

	// Calculate popularity for each vertex
	for (Vertex v = 0; v < nV; v++) {
		int in = inDegree(g, v);
		int out = outDegree(g, v);

		double popularity;
		if (out == 0) {
			popularity = (double)in / 0.5;
		}
		else {
			popularity = (double)in / (double)out;
		}

		popularityArray[v].vertex = v;
		popularityArray[v].popularity = popularity;
	}

	// Sort the popularity array
	insertionSort(popularityArray, nV);

	// Print the popularity array with the vertex number.
	printf("Popularity ranking:\n");
	for (int i = 0; i < nV; i++) {
		printf("%d %.1f\n", popularityArray[i].vertex, popularityArray[i].popularity);
	}

	// Free allocated resources
	freeGraph(g);
	free(popularityArray);

	return 0;
}
