#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int array[], int size);
void swap(int *xp, int *yp);
void shakerSort(int array[], int n);
 

int main() {
    int array[] = {9, 4, 1, 8, 1, 2, 6, 3, 5, 7};
    int n = sizeof(array)/sizeof(array[0]);

    printArray(array, n);
    shakerSort(array, n);
    printf("Sorted array: \n");
    printArray(array, n);

    return 0;
}


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void shakerSort(int array[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

	while (swapped) {
		swapped = false;
		for (int i = start; i < end; i++) {
			if (array[i] > array[i + 1]) {
				swap(&array[i], &array[i + 1]);
				swapped = true;
			}
		}

		if(!swapped) break;
		swapped = false;

		end--;

		for (int j = end; j >= start; j--) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		start++;
	}
}
 
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
