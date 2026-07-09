// Insertion sort on a global array

#include <stdio.h>
#include <stdlib.h>

int numbers[] = { 40, 20, 30 };

void insertionSort(int array[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int element = array[i];
		for (j = i - 1; j >= 0 && array[j] > element; j--) {
			array[j + 1] = array[j];
		}
		array[j + 1] = element;
	}
}

int main(void) {

	insertionSort(numbers, 3);
	return 0; // Program executed successfully.
}
