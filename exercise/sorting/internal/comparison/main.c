#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


/* INSERTION SORT
 * O(n²) = Quadratic
 * Os(S(n)) = O(1) - Linear
 *          - In place
 * Naturality = YES
 * Stability = YES
 * Sequencity = YES
 * */

void insertionSort(float array[], int n) {
    for (int i = 1; i < n; i++) {
        float current = array[i];
        int j = i - 1;
 
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}


void insertionSortWithBreak(float array[], int size) {
    int j;
	float inner;

    for (int i = size - 2; i > 0; i--) {
		array[size - 1] = array[i];
        inner = array[i];
		j = i;
 
        while (array[j + 1] < inner) {
            array[j] = array[j + 1];
            j = j + 1;
        }
        array[j] = inner;
    }
}

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}


/* SELECTION SORT
 * T(n) = O(n²) - quadratic
 *		- Two nested cycles with linear complexity
 * Os(S(n)) = O(1) - linear
 *		- In situ = In-place Algorithm
 * Natural = NO 
 * Sequential = YES
 * Stability = NO
 * */
 
void selectionSort(float array[], int n) {
    int min_idx;

    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        swap(&array[min_idx], &array[i]);
    }
}


/* BUBBLE SORT
 * O(n²) = Quadratic
 * Os(S(n)) = O(1) - Linear
 *          - In place
 * Naturality = NO (but optimized versions are)
 * Stability = YES
 * Sequencity = YES
 * */

void bubbleSort(float array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
		}
    }
}

void rippleSort(float array[], int n) {
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
    }
}

void shakerSort(float array[], int n) {
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


/* QUICK SORT
 * T(n) = O(n log n) - linearithmic
 *		- O(n²) = worst case 
 * Os(n) = O(n)
 *		 - NOT In Place
 * Natural = YES (depends on the pivot)
 * Sequential = YES 
 * Stability = NO
 * Recursive
 * */

void swapQ(float array[], int x, int y) {
	float temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

static inline
int partition(float array[], int start, int end) {
	int p = (start + end)/2; // or other selection
	float pivot = array[p];
	swapQ(array, p, start); // pivot removal on site

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

		swapQ(array,left, right);
	} // while
	
	swapQ(array, right, start); // inserting pivot on final position
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


/* MERGE SORT
 * T(n) = O(n log n) - linearithmic
 * Os(n) = O(n)
 *		 - Not In Place
 * Natural = NO 
 * Sequential = YES 
 * Stability = YES
 * Recursive
 * */

static inline
void merge(float array[], float temp_array[], int start, int middle, int end) {
	int temp = start;
	int left = start;
	int right = middle + 1;

	 while (left <= middle && right <= end) {
		temp_array[temp++] = array[left] <= array[right] ? array[left++] : array[right++];
	}

	while (left <= middle) {
		temp_array[temp++] = array[left++];
	}
	while (right <= end) {
		temp_array[temp++] = array[right++];
	}
}

void copyPartOfArray(float array[], float temp_array[], int start, int end) {
	for (int index = start; index <= end; index++) {
		array[index] = temp_array[index];
	}
}

void _mergeSort(float array[], float temp_array[], int start, int end) {

	if (start < end) {
		int middle = (start + end) / 2;

		_mergeSort(array, temp_array, start, middle);
		_mergeSort(array, temp_array, middle + 1, end);

		merge(array, temp_array, start, middle, end);

		/* array[start, end] = temp_array[start, end]; */
		copyPartOfArray(array, temp_array, start, end);
	}
}

void mergeSort(float array[], int n) {
	float temp_array[n];
	_mergeSort(array, temp_array, 0, n - 1);
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


    test(from, to, "insertion", insertionSort);
    test(from, to, "insertionWithBreak", insertionSortWithBreak);
    test(from, to, "bubble", bubbleSort);
    test(from, to, "ripple", rippleSort);
    test(from, to, "selection", selectionSort);
    test(from, to, "shaker", shakerSort);
    test(from, to, "quickSort", quickSort);
	test(from, to, "mergeSort", mergeSort);
	printf("\n[FAIL-INFO] Insertion sort with break fails because it has it's break\n");

    fclose(from);
    fclose(to);

	return 0;
}

