/* T(n) = O(n log n) - logarithmic
 * Os(n) = O(n)
 *		 - Not In Situ
 * Natural = NO 
 * Sequential = YES 
 * Stability = YES
 * 
 * Recursive
 * */

#include <stdio.h>
#include <stdlib.h>


void merge(int array[], int l, int m, int r);
void mergeSort(int array[], int l, int r);
void printArray(int array[], int n);

 
int main() {
    int array[] = {2, 4, 1, 6, 8, 5, 3, 7};
    int array_size = sizeof(array) / sizeof(array[0]);

    printf("Given array: \n");
    printArray(array, array_size);

	mergeSort(array, 0, array_size - 1);

    printf("\nSorted array: \n");
    printArray(array, array_size);

    return 0;
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// l = left index and r = right index of the subarray of array to be sorted
void mergeSort(int array[], int l, int r) {
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);

		merge(array, l, m, r);
	}
}

 
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

