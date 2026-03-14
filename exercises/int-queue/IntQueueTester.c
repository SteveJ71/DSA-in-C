// Interactive tester for the Integer Queue ADO

#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int main(void) {
	int i, n;
	char str[BUFSIZ];

	QueueInit();

	printf("Enter number of integers to add to the queue: ");
	scanf("%s", str);
	if ((n = atoi(str)) > 0) {    // convert to int and test if positive
		for (i = 0; i < n; i++) {
			printf("Enter a number: ");
			scanf("%s", str);
			QueueEnqueue(atoi(str));
		}
	}

	//output the n numbers in reverse order
	while (!QueueIsEmpty()) {
		printf("%d\n", QueueDequeue());
	}


	return 0;
}
