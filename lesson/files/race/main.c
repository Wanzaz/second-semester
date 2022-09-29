#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number_of_runner;
	float performance;
} TRunner;


int findWinner(FILE *input, FILE *output) {
	TRunner runner;
	int max_runner;
	float max_performance;

	if (fscanf(input,"%d%f", &max_runner, &max_performance) != 2) {
		fprintf(stdin, "There are not any runners");
		return -1;
	}

	while (fscanf(input,"%d%f", &runner.number_of_runner, &runner.performance) == 2) {
		if (max_performance < runner.performance) {
			max_runner = runner.number_of_runner;
			max_performance = runner.performance;
		}
	}


	return max_runner;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Run like this: clang -std=c17 -o main main.c;./main runners.txt winner.txt \n");
		return EXIT_FAILURE;
	}

	char *inputpath = "runners.txt";
	char *outputpath = "winner.txt";

	FILE *file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!", inputpath);
		return EXIT_FAILURE;
	}

	FILE *result = fopen(outputpath, "w");
	if (result == NULL) {
		fprintf(stderr, "Output file %s is unable to open!", outputpath);
		return EXIT_FAILURE;
	}

	fprintf(result, "The number of the runner winner is %d\n", findWinner(file, result));

	fclose(file);
	fclose(result);

	return 0;
}

