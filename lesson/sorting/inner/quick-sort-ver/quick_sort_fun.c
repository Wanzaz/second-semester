/* QUICK SORT
 * T(n) = O(n log n) - linearithmic
 *		- O(n²) = worst case 
 * Os(n) = O(n)
 *		 - NOT In Place
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

void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void quicksort(int array[],int start,int end){
   int left, right, pivot;
   if (start < end) {
      pivot = start;
      left = start;
      right = end;
      while (left < right) {
         while (array[left] <= array[pivot] && left < end) {
			 left++;
		 }
         while (array[right] > array[pivot]) {
			 right--;
		 }
         if (left < right) {
			swap(&array[right], &array[left]);
         }
      }
	  swap(&array[right], &array[pivot]);

      quicksort(array, start, right - 1);
      quicksort(array, right + 1, end);
   } //while (start < end);
}

int main() {
	int array[] = {2, 4, 1, 6, 8, 5, 3, 7};

    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted Array\n");
    printArray(array, size);

    // perform quicksort on data
    quicksort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);
}



