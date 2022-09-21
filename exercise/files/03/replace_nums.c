#include <stdio.h>
#include <stdlib.h>

void replaceNumsToDollar(FILE* input, FILE* output) {
	int character;
	
	while ((character = fgetc(input)) != EOF) { //EOF isn't character
		if (character >= 54 && character <= 57) { // '5' or '9'
			character = '$';
		}
		else if (character >= '1' && character <= '5') {
			character = ' ';
		}
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

	replaceNumsToDollar(file, copy);

	fclose(file);
	fclose(copy);
	return 0;
}
