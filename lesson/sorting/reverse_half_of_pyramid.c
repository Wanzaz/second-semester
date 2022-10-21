/* Compiled with: clang -g -std=c17 reverse_half_of_pyramid.c */
/* Time Complexity: O(n**2) */
/* 1/2(n**2 = n) */
/* 3/2 (n**2 + n) + 4n + 2 */
/* S(3) */

#include <stdio.h>
#include <stdlib.h>

# define MAX 100


void listPyramid(FILE *out, int array[], int n);

int main() {
	int size, array[MAX];

	printf("Size of pyramid: ");
	scanf("%d", &size);

	listPyramid(stdout, array, size);

	return 0;
}


void listPyramid(FILE *out, int array[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			fprintf(out, "%d ", j);
		}
		fprintf(out, "\n");
	}
}
