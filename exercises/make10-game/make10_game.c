// Make 10 Game: given 4 digits from a train number, find arithmetic expressions that equal 10.
// Uses Heap's Algorithm to generate all permutations of the 4 digits,
// then tries all combinations of operators (+, -, *, /, ^) and parenthesisations.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define SUM(a,b)      ((double)a + (double)b)
#define DIFF(a,b)     ((double)a - (double)b)
#define MULTIPLY(a,b) ((double)a * (double)b)
#define DIVIDE(a,b)   ((double)a / (double)b)
#define POWER(a,b)    (pow((double)a, (double)b))

int countZeros(int input[], int size) {

	int count = 0;

	for (int i = 0; i < size; i++) {
		if (input[i] == 0) {
			count++;
		}
	}

	return count;

}


double join(double a, double b, char operator) {
	if (operator == '+') {
		return SUM(a, b);
	}
	else if (operator == '-') {
		return DIFF(a, b);
	}
	else if (operator == '*') {
		return MULTIPLY(a, b);
	}
	else if (operator == '/') {
		return DIVIDE(a, b);
	}
	else if (operator == '^') {
		return POWER(a, b);
	}
	return 0;
}

char operator(int index) {
	if (index == 0) {
		return '+';
	}
	else if (index == 1) {
		return '-';
	}
	else if (index == 2) {
		return '*';
	}
	else if (index == 3) {
		return '/';
	}
	else if (index == 4) {
		return '^';
	}
	return '+';
}

void hasSolution(int myArray[4]) {

	int noZeros = countZeros(myArray, 4);

	// 3 zero case - no solution
	if (noZeros > 2) {
		printf("No Solution Found\n");
		return;
	}

	int a = myArray[0];
	int b = myArray[1];
	int c = myArray[2];
	int d = myArray[3];
	double ab = 0;
	double bc = 0;
	double cd = 0;
	char op1 = '+';
	char op2 = '+';
	char op3 = '+';

	for (int j = 0; j < 5; j++) {						// First Operator
		op1 = operator(j);
		for (int l = 0; l < 5; l++) {				// Second Operator
			op2 = operator(l);
			for (int n = 0; n < 5; n++) {		// Third Operator
				op3 = operator(n);

				// Compute pair joins
				ab = join(a, b, op1);
				bc = join(b, c, op2);
				cd = join(c, d, op3);

				//	ab.cd
				if (join(ab, cd, op2) == 10.0) {
					printf("Solution found: (%d%c%d)%c(%d%c%d)=10\n", a, op1, b, op2, c, op3, d);
				}

				//	(a.bc).d
				if (join(join(a, bc, op1), d, op3) == 10.0) {
					printf("Solution found: (%d%c(%d%c%d))%c%d=10\n", a, op1, b, op2, c, op3, d);
				}

				//	a.(bc.d)
				if (join(a, join(bc, d, op3), op1) == 10.0) {
					printf("Solution found: %d%c((%d%c%d)%c%d)=10\n", a, op1, b, op2, c, op3, d);
				}

				//	(ab.c).d
				if (join(join(ab, c, op2), d, op3) == 10.0) {
					printf("Solution found: ((%d%c%d)%c%d)%c%d=10\n", a, op1, b, op2, c, op3, d);
				}

				//	a.(b.(c.d))
				if (join(a, join(b, join(c, d, op3), op2), op1) == 10.0) {
					printf("Solution found: %d%c(%d%c(%d%c%d))=10\n", a, op1, b, op2, c, op3, d);
				}
			}
		}
	}
}


// Generating permutation using Heap's Algorithm

void heapPermutation(int a[], int size, int n)
{
	// if size becomes 1 then prints the obtained
	// permutation
	if (size == 1) {

		/*printArr(a, n);*/
		hasSolution(a);
		return;
	}

	int temp = 0;

	for (int i = 0; i < size; i++) {
		heapPermutation(a, size - 1, n);

		// if size is odd, swap 0th i.e (first) and
		// (size-1)th i.e (last) element
		if (size % 2 == 1) {
			temp = a[0];
			a[0] = a[size -1];
			a[size - 1] = temp;
		}

		// If size is even, swap ith and
		// (size-1)th i.e (last) element
		else {
			temp = a[i];
			a[i] = a[size - 1];
			a[size - 1] = temp;
		}

	}

}

int main(int argc, char *argv[]) {

	if (argc != 2 || strlen(argv[1]) != 4) {
		printf("Usage: %s <4-digit number>\n", argv[0]);
		printf("Example: %s 5341\n", argv[0]);
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		if (argv[1][i] < '0' || argv[1][i] > '9') {
			printf("Error: all characters must be digits (0-9)\n");
			return 1;
		}
	}

	int input[4];
	for (int i = 0; i < 4; i++) {
		input[i] = argv[1][i] - '0';
	}

	printf("\nMake 10 Game\n\n");
	printf("Train Number: %s\n\n", argv[1]);

	// use heaps algorithm to use all combinations of input.

	int n = sizeof input / sizeof input[0];
	heapPermutation(input, n, n);

	printf("finished!!!!\n");

	return 0;
}
