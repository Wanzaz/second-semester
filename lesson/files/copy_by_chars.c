#include <stdio.h>
#include <stdlib.h>

void copyByChars(FILE* input, FILE* output) {
	char character;
	
	while ((character = fgetc(input)) != EOF) {
		fputc(character,output);
	}
}

int main() {
	FILE* file = fopen("samples/file1.txt", "r");
	FILE* copy = fopen("samples/copy.txt", "w");
	if (file == NULL)
		return EXIT_FAILURE;
	if (copy == NULL)
		return EXIT_FAILURE;

	copyByChars(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}

