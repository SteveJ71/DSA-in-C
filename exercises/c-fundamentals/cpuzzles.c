// C Puzzle D31: reverse the elements in an array
// Note: fillArrayInOrder arguments are swapped at the call site — bug preserved

#include <stdio.h>
#include <stdlib.h>

#define SIZE 35


void reverseArray(int size, int arr[])
{
    int j;
    int temp;
    for (j = 0; j < size / 2; j++)
    {
        temp = arr[j];
        arr[j] = arr[size - j - 1];
        arr[size - j - 1] = temp;
    }
}

void fillArrayInOrder(int size, int arr[])
{
    int i;
    int j;

    int temp[SIZE];

    for (j = 0; j < size; j++)
    {
        i = size - j;
        temp[i] = arr[j];
    }

}

void printArray(int size, int arr[])
{
    const int N = 10;
    int j;

    for (j = 0; j < size; j++)
    {
        if (j % N == N - 1)
            printf("%4d\n", arr[j]);
        else
            printf("%4d ", arr[j]);
    }
}

int main(int argc, char* argv[])
{

    int x[SIZE];

    fillArrayInOrder(x, SIZE);
    printf("Original:\n");
    printArray(SIZE, x);
    printf("\nReversed:\n");
    reverseArray(SIZE, x);
    printArray(SIZE, x);

    printf("\n\n");
    system("PAUSE");	/* delete if not needed */
    return 0;
}
