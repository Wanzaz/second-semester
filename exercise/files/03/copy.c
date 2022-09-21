#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void copyByNums(FILE* input, FILE* output) {
	int number;
	
	while ((fscanf(input, "%d", &number)) == 1) {
		fprintf(output, "%d\n", number);
	}
}

void copyByChars(FILE* input, FILE* output) {
	int character;
	
	while ((character = fgetc(input)) != EOF) { //EOF isn't character
		fputc(character,output);
	}
}

int main(int argc, char **argv) {

	if (argc != 4) {
		fprintf(stderr, "Run like this: program option inputfile outputfile\n"
				        "             option  - char or num - copy by chars and nums\n");
		return EXIT_FAILURE;
	}

	if (strcmp(argv[1], "char") != 0 && strcmp(argv[1],"num") != 0) {
		fprintf(stderr, "Don't understand 1. paramter");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[2];
	char *outputpath = argv[3];

	FILE* file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!", inputpath);
		return EXIT_FAILURE;
	}

	FILE* copy = fopen(outputpath, "w");
	if (copy == NULL) {
		fprintf(stderr, "Input file %s is unable to open!", inputpath);
		return EXIT_FAILURE;
	}

	if (strcmp(argv[1], "char") == 0) {
		printf("------------------------------------------");
		printf("Task 1 - Copy By Characters\n");
		copyByChars(file, copy);
		printf("Task 1 - Copy Is Done\n");
		printf("------------------------------------------");
	}
	else if (strcmp(argv[1], "num")) {
		printf("------------------------------------------");
		printf("Task 2 - Copy By Numbers\n");
		copyByNums(file, copy);
		printf("Task 2 - Copy Is Done\n");
		printf("------------------------------------------");
		
	}

	fclose(file);
	fclose(copy);

	return 0;
}
