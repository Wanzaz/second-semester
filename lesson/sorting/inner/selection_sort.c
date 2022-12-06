/* T(n) = O(n²) - quadratic
 *		- Two nested cycles with linear complexity
 * Os(S(n)) = O(1) - linear
 *		- In situ = In-place Algorithm
 * Natural = NO 
 * Sequential = YES
 * Stability = NO
 * */

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size);
void swap(int *xp, int *yp);
void selectionSort(int array[], int n);
 

int main() {
    int array[] = {9, 4, 1, 8, 1, 2, 6, 3, 5, 7};
    int n = sizeof(array)/sizeof(array[0]);

    printArray(array, n);
    selectionSort(array, n);
    printf("Sorted array: \n");
    printArray(array, n);

    return 0;
}


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int array[], int n) {
    int min_idx;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        /* if(min_idx != i) */
        swap(&array[min_idx], &array[i]);
    }
}
 
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
