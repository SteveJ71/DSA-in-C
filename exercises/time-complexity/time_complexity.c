// Count primitive operations in a nested loop to illustrate O(n²) time complexity

#include <stdio.h>

int main() {
    int n, i, j;
    int outerCount = 0; // Counter for the outer loop
    int innerCount = 0; // Counter for the inner loop
    int assignmentCount = 0; // Counter for the assignment operations
    int totalCount = 0; // Counter for the total number of primitive operations

    // Prompt user to enter the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Nested for loop
    for (i = 0; i < n; i++) {
        outerCount++; // Increment for the condition check in the outer loop
        for (j = 0; j < n; j++) {
            innerCount++; // Increment for the condition check in the inner loop
            // Assignment operation
            int x = i + j;
            assignmentCount+= 2; // Increment for the assignment and addition operations
        }
        innerCount++; // Increment for the final condition check in the inner loop
    }
    outerCount++; // Increment for the final condition check in the outer loop

    // Calculate the total count of primitive operations
    totalCount = outerCount + innerCount + assignmentCount;

    // Print the counts
    printf("Outer loop count: %d\n", outerCount);
    printf("Inner loop count: %d\n", innerCount);
    printf("Assignment operations count: %d\n", assignmentCount);
    printf("Total primitive operations: %d\n", totalCount);

    return 0;
}
