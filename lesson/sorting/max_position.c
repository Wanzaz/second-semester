/* Compiled with: clang -g -std=c17 max_position.c */
/* Tn(n) = 4n + 7 */
/* Time Complexity: O(n) */

#include <stdio.h>
#include <stdlib.h>

# define MAX 100


void swapMaxWithLasOne(int array[], int n);
void listArray(FILE *out, int array[], int n);
void retriveArrayElements(FILE *in, FILE *out, int array[], int n);

int main() {
	int size, array[MAX];

	printf("Size of array: ");
	scanf("%d", &size);

	retriveArrayElements(stdin, stdout, array, size);
	listArray(stdout, array, size);
	swapMaxWithLasOne(array, size);
	fprintf(stdout, "\n");
	listArray(stdout, array, size);


	return 0;
}


void swapMaxWithLasOne(int array[], int n) {
	int max_position = 0;

	for (int i = 1; i < n; i++) {
		if (array[max_position] < array[i]) {
			max_position = i;
		}
	}

	int tmp = array[max_position];
	array[max_position] = array[n - 1];
	array[n - 1] = tmp;
}

void listArray(FILE *out, int array[], int n) {
	for (int i = 0; i < n; i++) {
		fprintf(out, "%d ", array[i]);
	}
}

void retriveArrayElements(FILE *in, FILE *out, int array[], int n) {
	for (int i = 0; i < n; i++) {
		fprintf(out, "%d. Element of array: ", i + 1);
		fscanf(in, "%d", &array[i]);
	}
}
