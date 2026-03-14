// Priority Queue ADO header

#include "WGraph.h"
#include <stdbool.h>

#define MAX_NODES 1000

void   PQueueInit();        // set up empty priority queue
void   joinPQueue(Vertex);  // insert vertex v into priority queue
                            // no effect if v is already in the queue
Vertex leavePQueue(int[]); // remove the highest priority vertex from the priority queue
                            // remember: highest priority = lowest value priority[v]
                            // returns the removed vertex
bool   PQueueIsEmpty();     // check if the priority queue is empty
