#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Most of the code was written by MAJKEL

void loadFileToArray(FILE* from, float numbers[], int size);
void put(FILE* to, float numbers[], int size);
void test(FILE* data, FILE* to, char name[], void (*sort)(float[], int));
bool isSorted(float numbers[], int size);
void selectionSort(float numbers[], int size);
void insertionSort(float numbers[], int size);
void insertionSortWithBreak(float numbers[], int size);
void bubbleSort(float numbers[], int size);
void rippleSort(float numbers[], int size);
void swap(float *xp, float *yp);
void shakerSort(float array[], int size);

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
	printf("\n[FAIL-INFO] Insertion sort with break fails because it has it's break\n");

    fclose(from);
    fclose(to);

    return 0;
}

void loadFileToArray(FILE* from, float numbers[], int size) {
    int i = 0;
    while (i < size && fscanf(from, "%f", &numbers[i]) == 1) {
        i++;
    }
}

void put(FILE* to, float numbers[], int size) {
    fprintf(to, "%i\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(to, "%f\n", numbers[i]);
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

void test(FILE* data, FILE* to, char name[], void (*sort)(float[], int)) { 
    int size;
    fscanf(data, "%i", &size); 

    float numbers[size + 1];
    loadFileToArray(data, numbers, size);

    sort(numbers, size);
    printf("[TEST] %s: %s\n", name, isSorted(numbers, size) ? "PASS" : "FAIL");
    put(to, numbers, size);
}

void selectionSort(float numbers[], int size) {
    for (int index = 0; index < size; index++) {
        float smallest = numbers[index];
        int smallest_index = index;
        for (int inner = index + 1; inner < size; inner++) {
            if (numbers[inner] < smallest) {
                smallest = numbers[inner];
                smallest_index = inner;
            }
        }
        float temp = numbers[smallest_index];
        numbers[smallest_index] = numbers[index];
        numbers[index] = temp;
    }
}

void insertionSort(float numbers[], int size) {
    for (int index = 1; index < size; index++) {
        int inner = index;
        float current = numbers[index];
        while (inner > 0 && numbers[inner - 1] > current) {
            numbers[inner] = numbers[inner - 1];
            inner--;
        }
        numbers[inner] = current;
    }
}

void insertionSortWithBreak(float numbers[], int size) {
    for (int index = size - 2; index > 0; index--) {
        int inner = index;
        float current = numbers[index];
        numbers[size] = current;
        while (current > numbers[inner + 1]) {
            numbers[inner] = numbers[inner + 1];
            inner++;
        }
        numbers[inner] = current;
    }
}

void bubbleSort(float numbers[], int size) {
    float h;
    for (int end = size - 1; end > 0; end--) {
        for (int index = 0; index < end; index++) {
            if (numbers[index] > numbers[index + 1]) {
                h = numbers[index];
                numbers[index] = numbers[index + 1];
                numbers[index + 1] = h;
            }
        }
    }
}

void rippleSort(float numbers[], int size) {
    float h;
    int last;
    for (int end = size - 1; end > 0; end = last) {
        last = 0;
        for (int index = 0; index < end; index++) {
            if (numbers[index] > numbers[index + 1]) {
                h = numbers[index];
                numbers[index] = numbers[index + 1];
                numbers[index + 1] = h;
                last = index;
            }
        }
    }
}

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shakerSort(float array[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

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

