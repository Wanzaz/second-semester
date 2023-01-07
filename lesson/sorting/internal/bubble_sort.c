/* BUBBLE SORT
 * O(n²) = Quadratic
 * Os(S(n)) = O(1) - Linear
 *          - In place
 * Naturality = NO (but optimized versions are)
 * Stability = YES
 * Sequencity = YES
 * */

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[], int n);
void printArray(int array[], int n);
void swap(int *xp, int *yp);

 
int main() {
    int array[] = {2, 8, 7, 1, 5, 4, 3, 6, 9, 10, 0};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: \n");
    printArray(array, n);

    printf("Process of sorting array: \n");
    bubbleSort(array, n);

    printf("Sorted array: \n");
    printArray(array, n);

    return 0;
}


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int n) {
	bool swapped;

	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				swapped = true;	
			}
		}
		if (swapped == false) break;
		printArray(array, n);
	}
}
 
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
