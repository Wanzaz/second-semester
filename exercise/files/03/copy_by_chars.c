#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void copyByChars(FILE* input, FILE* output) {
	int character;
	
	while ((character = fgetc(input)) != EOF) { //EOF isn't character
		fputc(character,output);
	}
}


int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Run like this: program option inputfile outputfile\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];
	char *outputpath = argv[2];

	FILE* file = fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", inputpath);
		return EXIT_FAILURE;
	}

	FILE* copy = fopen(argv[2], "w");
	if (copy == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", outputpath);
		return EXIT_FAILURE;
	}

	copyByChars(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}

