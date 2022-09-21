#include <stdio.h>
#include <stdlib.h>

void copyByNums(FILE* input, FILE* output) {
	int number;
	
	while ((fscanf(input, "%d", &number)) == 1) {
		fprintf(output, "%d\n", number);
	}
}

int main(int argc, char **argv) {
	FILE* file = fopen(argv[1], "r");
	FILE* copy = fopen(argv[2], "w");
	if (file == NULL)
		return EXIT_FAILURE;
	if (copy == NULL)
		return EXIT_FAILURE;

	copyByNums(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}
