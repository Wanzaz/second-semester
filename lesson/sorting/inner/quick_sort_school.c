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


// function to swap elements
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// function to find the partition position
void partition(int array[], int start, int end, int pivot, int *left, int *right) {
	*left = start;
	*right = end;

	do {
		while (array[*left] < pivot && *left < end) ++*left;
		while (pivot < array[*right] && *right > start) --*right;

		if (*left < *right) {
			swap(&array[*left], &array[*right]);
		}
		if (*left <= *right) {
			++*left;
			--*right;
		}
	
	} while (*left < *right);
}

void quickSort(int array[], int start, int end) {
	int left, right; 

	if (start < end) {
		int pivot = array[(start + end) / 2];

		partition(array, start, end, pivot, &left, &right);

		quickSort(array, start, right);
		quickSort(array, left, end);
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = {2, 4, 1, 6, 8, 5, 3, 7};

    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array\n");
    printArray(array, size);

    // perform quicksort on data
    quickSort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);
}


