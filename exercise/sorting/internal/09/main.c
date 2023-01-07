#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isSorted(float array[], int size);
void readingFileToArray(FILE *output, float array[]);
void insertionSort(float array[], int n);
void insertionSortWithStopAtStart(float array[], int n);
void insertionSortWithStopAtEnd(float array[], int n);
void printArray(FILE *output, float array[], int n);
void printArrayWithStop(FILE *output, float array[], int n);
void dividingCode(int size);
void swap(float *xp, float *yp);
void selectionSort(float array[], int n);
void bubbleSort(float array[], int n);
void rippleSort(float array[], int n);
void shakerSort(float array[], int n);


int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];

	FILE* file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", inputpath);
		return EXIT_FAILURE;
	}

	int size;
	fscanf(file, "%d", &size);
	float array[size + 1];
	readingFileToArray(file, array);

	printf("Unsorted array: \n");
	printArray(stdout, array, size);

	printf("Sorted: %s", isSorted(array, size) ? "true\n" : "false\n");

	dividingCode(150);

	printf("Sorted array: \n");
	insertionSort(array, size);
	/* selectionSort(array, size); */
	/* insertionSortWithStopAtStart(array, size + 1); */
	/* insertionSortWithStopAtEnd(array, size + 1); */
	/* bubbleSort(array, size); */
	/* rippleSort(array, size); */
	shakerSort(array, size);

	/* printArrayWithStop(stdout, array, size); */
	printArray(stdout, array, size);

	printf("Sorted: %s", isSorted(array, size) ? "true\n" : "false\n");

	return 0;
}

bool isSorted(float array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) return false;
	}
	return true;
}


void readingFileToArray(FILE *output, float array[]) {
	float number;
	int i = 0;

	while (fscanf(output, "%f", &number) == 1) {
		array[i] = number;
		i++;
	}
}

void insertionSort(float array[], int n) {
    int j;
	float key;

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


void insertionSortWithStopAtStart(float array[], int n) {
    int j;
	float key;

    for (int i = 2; i < n - 1; i++) {
		array[0] = array[i];
        key = array[i];
		j = i;
 
        while (array[j - 1] > key) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = key;
    }
}

 
void insertionSortWithStopAtEnd(float array[], int n) {
    int j;
	float key;

    for (int i = n - 2; i > 0; i--) {
		array[n - 1] = array[i];
        key = array[i];
		j = i;
 
        while (array[j + 1] < key) {
            array[j] = array[j + 1];
            j = j + 1;
        }
        array[j] = key;
    }
}

void printArrayWithStop(FILE *output, float array[], int n) {
    for (int i = 1; i < n; i++) // i = 1 because of the insertionSortWithStop
        fprintf(output, "%0.1f ", array[i]);
    printf("\n");
}

void printArray(FILE *output, float array[], int n) {
    for (int i = 0; i < n; i++)
        fprintf(output, "%0.1f ", array[i]);
    printf("\n");
}

void dividingCode(int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("-");
	}
	printf("\n\n");
}

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(float array[], int n) {
    int min_idx;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        /* if(min_idx != i) */
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
