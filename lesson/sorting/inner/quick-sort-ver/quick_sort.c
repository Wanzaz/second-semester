/* T(n) = O(n log n) - logarithmic
 *		- O(n²) = worst case 
 * Os(n) = O(n)
 *		 - In Situ
 * Natural = YES (depends on the pivot)
 * Sequential = YES 
 * Stability = NO
 * 
 * Recursive
 * */

#include <stdio.h>
#include <stdlib.h>


void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *xp, int *yp);
void printArray(int array[], int size);


int main() {
	int array[] = {2, 4, 1, 6, 8, 5, 3, 7};

    int n = sizeof(array) / sizeof(array[0]);

    printf("Unsorted Array\n");
    printArray(array, n);

    // perform quicksort on data
    quickSort(array, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(array, n);
}

// function to swap elements
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// function to find the partition position
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
         }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

