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
#include <stdbool.h>
#include <time.h>


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

void mergeSort(float array[], float temp_array[], int n) {
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

void test(FILE* data, FILE* to, char name[], void (*sort)(float[], float[], int)) { 
    int size;
    fscanf(data, "%i", &size); 

    float numbers[size + 1];
    float temp_numbers[size + 1];
    loadFileToArray(data, numbers, size);

	clock_t time = clock();

    sort(numbers, temp_numbers, size);

	time = clock() - time;
	double time_taken = ((double)time/CLOCKS_PER_SEC);
    printf("[TEST] %s: %s - %fs\n", name, isSorted(numbers, size) ? "PASS" : "FAIL", time_taken);
    put(to, numbers, size);
}

 
int main() {
    FILE* from = fopen("from.txt", "r");
    FILE* to = fopen("to.txt", "w");
    if (from == NULL || to == NULL) {
        return EXIT_FAILURE;
    }

    test(from, to, "mergeSort", mergeSort);

    return 0;
}



