// A program to check if a string is a heterogram (no repeated letters, ignoring spaces)

#define MAX_LENGTH 63

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to determine if a string is a heterogram
bool isHeterogram(char str[]) {

	int len = strlen(str);

	// check each character against each other for duplicates
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (str[i] == str[j] && str[i] != ' ' && str[j] != ' ') {
					return false; // found duplicate character
			}
		}
	}
	return true; //No duplicates found, so its a heterogram.
}


int main(void) {

	char str[MAX_LENGTH + 1] =""; // Initialise to an empty string
								  // to handle case if user hits
								  // enter without entering a string

	// Prompt the user for input
	printf("Enter a word or phrase: ");
	scanf("%[^\n]%*c", str); // read line, discarding newline

	// Check if input is heterogram
	if (isHeterogram(str)) {
		printf("\"%s\" is a heterogram\n", str);
	}
	else {
		printf("\"%s\" is not a heterogram\n", str);
	}

	return 0;
}
