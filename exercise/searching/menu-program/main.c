#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

#define MAXSIZE 7000

/* typedef int Titem; */

static inline
bool isLess(int a, int b)
{
    return a < b;
}

static inline
bool isEqual(int a, int b)
{
    return a == b;
}

int seqSearch(int array[], int n, int key)
{
    int i = 0;
    
    while (i < n && !isEqual(array[i], key)) {
        i++;
    }

    if (i < n) return i;
    else return -1;
}

int seqSearchSimplified(int array[], int n, int key)//
{
    int i = 0;
    
    while (i < n && array[i] != key) {
        i++;
    }

    if (i < n) return i;
    else return -1;
}

int seqStopSearch(int array[], int n, int key)
{
    array[n - 1] = key;
    int i = 0;
    
    while (array[i] != key) {
        i++;
    }

    if (i < n) return i;
    else return -1;
}

int seqSortSearch(int array[], int n, int key)
{
    int i = 0;
    
    while (i < n && isLess(array[i], key)) {
        i++;
    }

    if (i < n && array[i] == key) return i;
    else return -1;
}


static inline
void merge(int array[], int temp_array[], int start, int middle, int end) {
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

void copyPartOfArray(int array[], int temp_array[], int start, int end) {
	for (int index = start; index <= end; index++) {
		array[index] = temp_array[index];
	}
}

void _mergeSort(int array[], int temp_array[], int start, int end) {

	if (start < end) {
		int middle = (start + end) / 2;

		_mergeSort(array, temp_array, start, middle);
		_mergeSort(array, temp_array, middle + 1, end);

		merge(array, temp_array, start, middle, end);

		copyPartOfArray(array, temp_array, start, end);
	}
}

void mergeSort(int array[], int temp_array[], int n) {
	_mergeSort(array, temp_array, 0, n - 1);
}

bool isSorted(int numbers[], int size)
{
    for (int index = 0; index < size - 1; index++) {
        if (numbers[index] > numbers[index + 1]) {
            return false;
        }
    }
    return true;
}

void loadFileToArray(FILE* from, int numbers[], int size)
{
    int i = 0;
    while (i < size && fscanf(from, "%d", &numbers[i]) == 1) {
        i++;
    }
}

int countNumbers(FILE *input, int array[]) {
	int i = 0;
	
	while (i < MAXSIZE && fscanf(input, "%d", &array[i]) == 1) {
		i++;
	}

	return i;
}

void put(FILE* to, int numbers[], int size)
{
    for (int i = 0; i < size; i++) {
        fprintf(to, "%d\n", numbers[i]);
    }
}

int testMerge(FILE* data, FILE* to, char name[], void (*sort)(int[],int [], int))
{ 
    int numbers[MAXSIZE + 1];
    int n = countNumbers(data, numbers);
    rewind(data);
    loadFileToArray(data, numbers, n);
    if (isSorted(numbers, n)) {
        return 0;
    }
    int temp_numbers[MAXSIZE + 1];

    sort(numbers, temp_numbers, n);

    printf("[TEST] %s: %s\n", name, isSorted(numbers, n) ? "PASS" : "FAIL");
    put(to, numbers, n);
    return 1;
}

void testSearchAlg(FILE* data, char name[], int (*search)(int[], int, int))
{ 
    int key = 9;
    int numbers[MAXSIZE + 1];
    int n = countNumbers(data, numbers);
    rewind(data);
    loadFileToArray(data, numbers, n);

    int returned_number = search(numbers, n, key);

    printf("[SEARCHING] %s: %s - on positon %d\n", name, (returned_number != -1) ? "FOUND" : "NOT FOUND", returned_number);
}

void pause(void)
{
    #if defined __WIN32 || defined __WIN64
        system("pause"); 
	#else 
		system("read a");
	#endif
}

void clear(void)
{
	#ifdef _WIN32 
		system("cls");
	#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	    system("clear");
	//add some other OSes here if needed
	#else
		#error "OS not supported."
	#endif
}

void menu(void)
{
	clear();   
	printf(
			"Searching Algorithms:\n"
			"0..............................exit\n"
			"1...........sequence-search-general\n"
			"2........sequence-search-simplified\n"
			"3........sequence-search-with-break\n"
			"4...sequence-search-in-sorted-array\n"
			"5..........binary-search-recurively\n"
			"6......binary-search-non-recurively\n"
			"Choose operation: "
		  );
}

int main (int argc, char *argv[])
{
    if (argc != 3) {
		fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile outputfile\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];
	char *outputpath = argv[2];

    FILE *inputfile = fopen(inputpath, "r");
    FILE *outputfile = fopen(outputpath, "w");


    int choice = 1;

    while (choice != 0) {
        menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                return 0;
            case 1:
                testSearchAlg(inputfile, "seqSearch", seqSearch);
                break;
            case 2:
                /* testSearchAlg(inputfile, "seqSearchSimplified", seqSearchSimplified); */
                break;
            case 3:
                testSearchAlg(inputfile, "seqStopSearch", seqStopSearch);
                break;
            case 4:
                /* if (testMerge(inputfile, outputfile, "mergeSort", mergeSort) == 0) { */
                /*     testSearchAlg(inputfile, "seqSortSearch", seqSortSearch); */
                /* } else { */
                /*     testSearchAlg(outputfile, "seqSortSearch", seqSortSearch); */
                /* } */
                break;
            case 5:
                break;
            case 6:
                break;
        }

        if (choice != 0)
			pause();
    } 

    
    return 0;
}

