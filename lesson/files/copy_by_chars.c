#include <stdio.h>
#include <stdlib.h>

void copyByChars(FILE* input, FILE* output) {
	int character;
	
	while ((character = fgetc(input)) != EOF) {
		fputc(character,output);
	}
}

int main() {
	FILE* file = fopen("file1.txt", "r");
	FILE* copy = fopen("copy.txt", "w");
	if (file == NULL)
		return EXIT_FAILURE;
	if (copy == NULL)
		return EXIT_FAILURE;

	copyByChars(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}

