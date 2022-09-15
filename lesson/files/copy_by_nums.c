#include <stdio.h>
#include <stdlib.h>

void copyByNums(FILE* input, FILE* output) {
	double number;
	
	while ((fscanf(input, "%lf", &number)) == 1) {
		fprintf(output, "%f\n", number);
	}
}

int main() {
	FILE* file = fopen("numbers.txt", "r");
	FILE* copy = fopen("copy.txt", "w");
	if (file == NULL)
		return EXIT_FAILURE;
	if (copy == NULL)
		return EXIT_FAILURE;

	copyByNums(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}

