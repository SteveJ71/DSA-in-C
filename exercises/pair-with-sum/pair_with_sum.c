// Brute-force O(n²) search for any pair of elements in an array that sum to a target value

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasPairWithSum(int A[], int size, int v) {

	int i, j;

	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {

			printf("A[%d]=%d and A[%d]=%d\n", i, A[i], j, A[j]);

			if (A[i] + A[j] == v){
				return true;
			}
		}
	}
	return false;
}

int main(void) {

	int A[6] = { 1,9,20,40,60,80 };
	int v = 82;

	bool ans = hasPairWithSum(A, 6, v);

	if (ans == true) {
		printf("Pair found!");
	}
	else {
		printf("Pair not found!");
	}

	return 0;
}
