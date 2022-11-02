#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numberOfPoints(const char *pattern, const char *answer) {
	int sum = 0;

	for (int i = 0; pattern[i] != '\0'; i++) {
		sum += (pattern[i] == answer[i]) ? 1 : 0;
	}

	return sum;
}


void results(FILE *vstup, FILE *vystup, const char *vzor) {
	char zak[3 + 1];
	int delka = strlen(vzor);
	char format[20];
	sprintf(format, "%%3s %%%ds", delka);
	char odpovedi[delka + 1];

	while (fscanf(vstup, format, zak , odpovedi) == 2) {
		fprintf(vystup, "%s %d\n", zak, numberOfPoints(vzor,odpovedi));
	}
}

FILE *parameter(int sequence, char *mod, int argc, char *argv[]) {
	if (strcmp(mod, "r") == 0) {
		if (argc <= sequence ||
				strcmp(argv[sequence], "--") == 0)
			return stdin;
	
	}
	else if (strcmp(mod, "w") == 0) {
		if (argc <= sequence ||
				strcmp(argv[sequence], "--") == 0)
			return stdout;
		
	}
	else 
		return NULL;

	return fopen(argv[sequence], mod);
}


int main(int argc, char **argv) {

	FILE *in = parameter(1, "r", argc, argv);
	FILE *out = parameter(2, "w", argc, argv);


	if (in == NULL || out == NULL) {
		printf("Wrong input parameters!\n"
			   "Run like this: clang main.c;./a.out exams.txt students_results.txt\n"
			   " - if first parameter won't be chosen it will be stdin\n"
			   " - if second parameter won't be chosen it will be stdout\n"
				);
		return 1;
	}

	results(in, out, "ABCDABCDAB");


	if (in != stdin) fclose(in);
	if (out != stdout) fclose(out);

	return 0;
}
