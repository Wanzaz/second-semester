#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


void insertionSort(float array[], int n) {
    int j;
	float key;

    for (int i = 1; i < n; i++) 
	{
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key) 
		{
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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
}

int main(void) {
    FILE* from = fopen("from.txt", "r");
    FILE* to = fopen("to.txt", "w");
    if (from == NULL || to == NULL) {
        return 1;
    }

	double time_taken;

    test(from, to, "insertion", insertionSort);
    test(from, to, "insertionWithBreak", insertionSortWithBreak);
    test(from, to, "bubble", bubbleSort);
    test(from, to, "ripple", rippleSort);
    test(from, to, "selection", selectionSort);
    test(from, to, "shaker", shakerSort);
	printf("\n[FAIL-INFO] Insertion sort with break fails because it has it's break\n");

    fclose(from);
    fclose(to);

	return 0;
}

