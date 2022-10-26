/* O(n) = Linear
 *      - worst case O(n²)
 * Os(S(n)) = O(1) - Linear
 *          - In situ
 * Naturality = YES
 * Stability = YES
 * Sequencity = YES
 * */

#include <math.h>
#include <stdio.h>

void insertionSort(int array[], int n);
void printArray(int array[], int n);

 
int main() {
    int array[] = {2, 8, 7, 1, 5, 4, 3, 6, 9, 10, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);

    insertionSort(array, n);
    printf("Sorted array: \n");
    printArray(array, n);

    return 0;
}


void insertionSort(int array[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) 
	{
        key = array[i];
        j = i - 1;
 
        /* Move elements of array[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && array[j] > key) 
		{
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
 
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
