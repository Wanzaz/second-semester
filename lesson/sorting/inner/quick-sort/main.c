/* T(n) = O(n log n) - logarithmic
 *		- O(n²) = worst case 
 * Os(n) = O(n)
 *		 - In Situ = In Place
 * Natural = YES (depends on the pivot)
 * Sequential = YES 
 * Stability = NO
 * 
 * Recursive
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// function to swap elements
void swap(float *xp, float *yp) {
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// function to find the partition position
static inline
int partition(float array[], int start, int end) {
	int p = (start + end)/2; // or other selection
	float pivot = array[p];
	swap(&array[p], &array[start]); // pivot removal on site

	int left = start;
	int right = end + 1;

	while (true) {
		while (array[++left] < pivot) {
			if (left == end) break; // find element >= pivot
		}
		while (pivot < array[--right]) {
			// this line doesn't have to be here - it shouldn't be executed in any time
			/* if (left == end) break; // find element >= pivot */ 
		}

		if (left >= right) break;

		swap(&array[left], &array[right]);
	} // while
	
	swap(&array[right], &array[start]); // inserting pivot on final position
	return right;
}

void _quickSort(float array[], int start, int end) {

	if (start >= end) return;

	int pivot_position = partition(array, start, end);

	_quickSort(array, start, pivot_position - 1);
	_quickSort(array, pivot_position + 1, end);
}

void quickSort(float array[], int n) {
	_quickSort(array, 0, n - 1);
	
}

void printArray(float array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%f ", array[i]);
	}
	printf("\n");
}

bool isSorted(float numbers[], int size) {
    for (int index = 0; index < size - 1; index++) {
        if (numbers[index] > numbers[index + 1]) {
            return false;
        }
    }
    return true;
}

void put(FILE* to, float numbers[], int size) {
    fprintf(to, "%i\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(to, "%f\n", numbers[i]);
    }
}

void loadFileToArray(FILE* from, float numbers[], int size) {
    int i = 0;
    while (i < size && fscanf(from, "%f", &numbers[i]) == 1) {
        i++;
    }
}

void test(FILE* data, FILE* to, char name[], void (*sort)(float[], int)) { 
    int size;
    fscanf(data, "%i", &size); 

    float numbers[size + 1];
    loadFileToArray(data, numbers, size);

	clock_t time = clock();

    sort(numbers, size);

	time = clock() - time;
	double time_taken = ((double)time/CLOCKS_PER_SEC);
    printf("[TEST] %s: %s - %fs\n", name, isSorted(numbers, size) ? "PASS" : "FAIL", time_taken);
    put(to, numbers, size);
	/* return time_taken; */
}


int main(void) {
    FILE* from = fopen("from.txt", "r");
    FILE* to = fopen("to.txt", "w");
    if (from == NULL || to == NULL) {
        return 1;
    }

    test(from, to, "quickSort", quickSort);

    fclose(from);
    fclose(to);

	return 0;
}


