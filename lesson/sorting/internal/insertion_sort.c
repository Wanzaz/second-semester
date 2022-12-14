/* INSERTION SORT
 * O(n) = Quadratic
 * Os(S(n)) = O(1) - Linear
 *          - In place
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
    int current, j;
    for (int i = 1; i < n; i++) 
	{
        current = array[i];
        j = i - 1;
 
        /* Move elements of array[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && array[j] > current) 
		{
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}
 
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
