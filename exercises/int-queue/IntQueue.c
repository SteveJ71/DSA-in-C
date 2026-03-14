// Queue ADT implementation — static array, non-circular (front index advances, no wrap-around)

#include "IntQueue.h"
#include <assert.h>

// define the Data Structure
typedef struct {
	int item[MAXITEMS];
	int  front;
	int end;
} queueRep;

// define the Data Object
static queueRep queueObject;

// set up empty queue
void QueueInit() {
	queueObject.front = 0;
	queueObject.end = -1;
}

// check whether queue is empty
int QueueIsEmpty() {
	return (queueObject.front > queueObject.end);
}

// insert int at end of queue
void QueueEnqueue(int integer) {
	assert(queueObject.end < MAXITEMS - 1);
	queueObject.end++;
	int i = queueObject.end;
	queueObject.item[i] = integer;
}

// remove int from front of queue
int QueueDequeue() {
	assert(queueObject.front <= queueObject.end);
	int integer = queueObject.item[queueObject.front];
	queueObject.front++;
	return integer;
}
