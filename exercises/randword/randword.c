// Generate a random word of lowercase letters.
// Usage: ./randword <length> <seed>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {

	if (argc != 3) {
		return 1;
	}

	int lengthWord = atoi(argv[1]);
	int seed = atoi(argv[2]);

	srand(seed);

	for (int i = 0; i < lengthWord; i++) {
		char random_char = 'a' + (rand() % 26);  // Random character between a and z
		printf("%c", random_char);
	}

	printf("\n");

	return 0;
}
