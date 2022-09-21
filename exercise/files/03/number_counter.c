#include <stdio.h>
#include <stdlib.h>

int numCounter(FILE* input) {
	int number;
	int amount_of_numbers=0;
	
	while ((fscanf(input, "%d", &number)) == 1) {
		amount_of_numbers += 1;
	}

	return amount_of_numbers;
}

int main(int argc, char **argv) {
	FILE* file = fopen(argv[1], "r");
	if (file == NULL)
		return EXIT_FAILURE;

	printf("The amount of numbers: %d\n", numCounter(file));

	fclose(file);
	return 0;
}
