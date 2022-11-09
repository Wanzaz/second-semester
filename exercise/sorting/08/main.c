#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* int sizeOfFile(FILE *input, int max_size); */
void readingFileToArray(FILE *output, float array[]);
void insertionSort(float array[], int n);
void printArray(FILE *output, float array[], int n);
void swap(float *xp, float *yp);
void selectionSort(float array[], int n);


int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: gcc main.c; ./a.out inputfile\n");
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
	float array[size];
	readingFileToArray(file, array);

	printf("Unsorted array: \n");
	printArray(stdout, array, size);

	printf("Sorted array: \n");
	/* insertionSort(array, size); */
	selectionSort(array, size);
	printArray(stdout, array, size);

	/* int size = sizeOfFile(file,  MAX); */
	return 0;
}

/* int sizeOfFile(FILE *input, int max_size) { */
/* 	int i=0, number; */
	
/* 	while (i < max_size && fscanf(input, "%d", &number) == 1) { */
/* 		i++; */
/* 	} */

/* 	return i; */
/* } */


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
 
void printArray(FILE *output, float array[], int n) {
    for (int i = 0; i < n; i++)
        fprintf(output, "%0.1f ", array[i]);
    printf("\n");
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
