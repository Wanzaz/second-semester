#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void rippleSort(int array[], int n);
void swap(int *xp, int *yp);
void printArray(FILE *output, int array[], int n);

int main(int argc, char **argv) {
	int array[] = {0, 1, 2, 3, 5, 6, 7, 4, 8, 9, 10};
	int size = sizeof(array) / sizeof(array[0]);
	
	printf("Unsorted array: \n");
	printArray(stdout, array, size);

	printf("Sorted array: \n");
	rippleSort(array, size);

	return 0;
}

void rippleSort(int array[], int n) {
	bool swapped;

    for (int i = 0; i < n - 1; i++) {
		swapped = false;
		printArray(stdout, array, n);
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
				swapped = true;
            }
		}
		if (swapped == false) break;
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(FILE *output, int array[], int n) {
    for (int i = 0; i < n; i++)
        fprintf(output, "%d ", array[i]);
    printf("\n");
}
