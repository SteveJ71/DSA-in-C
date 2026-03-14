// Boyer-Moore algorithm
// to match a pattern against text using the last-occurrence function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEXT_LENGTH 1024
#define TEXT_FORMAT_STRING "%[^\n]%*c"
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Computes the last-occurrence function for the Boyer-Moore algorithm
int* lastOccurance(char* pattern, char* alphabet) {

	int m = strlen(pattern);

	int *last = (int*)malloc(256 * sizeof(int));

	if (last == NULL) {
		return NULL;
	}

	memset(last, -1, 256 * sizeof(int));

	for (int i = 0; i < m; i++) {
		last[(int)pattern[i]] = i;
	}

	return last;
}

// Check if character is in the alphabet
bool isInAlphabet(char c, char* alphabet) {
	for (int i = 0; i < strlen(alphabet); i++) {
		if (alphabet[i] == c) {
			return true;
		}
	}
	return false;
}

int main(void) {

	char alphabet[127];
	char pattern[127];
	char text[MAX_TEXT_LENGTH];

	printf("Enter alphabet: ");
	if (scanf(TEXT_FORMAT_STRING, alphabet) != 1) {
		return 1;
	}
	printf("Enter text: ");
	if (scanf(TEXT_FORMAT_STRING, text) != 1) {
		return 1;
	}
	printf("Enter pattern: ");
	if (scanf(TEXT_FORMAT_STRING, pattern) != 1) {
		return 1;
	}

	int* L = lastOccurance(pattern, alphabet);

	if (L == NULL) {
		return 1;
	}

	// Print the last-occurrence array
	printf("\n");
	for (int i = 0; i < 256; i++) {
		char c = (char)i;
		if (isInAlphabet(c, alphabet)) {
			printf("L[%c] = %d\n", (char)i, L[i]);
		}
	}

	int m = strlen(pattern);
	int n = strlen(text);
	int i = m - 1;
	int j = m - 1;

	while (i < n) {
  		if (text[i] == pattern[j]) {
			if (j == 0) {
				printf("\nMatch found at position %d.\n", i);
				free(L);
				return 0;
			}
			else {
				i -= 1;
				j -= 1;
			}
		}
		else {
			i = i + m - MIN(j, 1 + L[(int)text[i]]);
			j = m - 1;
		}
	}

	printf("\nNo Match.\n");

	free(L);

	return 0;
}
