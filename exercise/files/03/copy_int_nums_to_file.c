#include <stdio.h>
#include <stdlib.h>

void copyByChars(FILE* input, FILE* output) {
	int character;
	
	while ((character = fgetc(input)) != EOF) { //EOF isn't character
		fputc(character,output);
	}
}


int main(int argc, char **argv) {
	FILE* file = fopen(argv[1], "r");
	FILE* copy = fopen(argv[2], "w");
	if (file == NULL)
		return EXIT_FAILURE;
	if (copy == NULL)
		return EXIT_FAILURE;

	copyByChars(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}
