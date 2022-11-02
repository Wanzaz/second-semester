#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pocetBodu(const char *vzor, const char *odpoved) {
	int suma = 0;

	for (int i = 0; vzor[i] != '\0'; i++) {
		suma += (vzor[i] == odpoved[i]) ? 1 : 0;
	}

	return suma;
}


void vysledky(FILE *vstup, FILE *vystup, const char *vzor) {
	char zak[3 + 1];
	int delka = strlen(vzor);
	char format[20];
	sprintf(format, "%%3s %%%ds", delka);
	char odpovedi[delka + 1];

	while (fscanf(vstup, format, zak , odpovedi) == 2) {
		fprintf(vystup, "%s %d\n", zak, pocetBodu(vzor,odpovedi));
	}
}

FILE *parametr(int poradi, char *mod, int argc, char *argv[]) {
	if (strcmp(mod, "r") == 0) {
		if (argc <= poradi ||
				strcmp(argv[poradi], "--") == 0)
			return stdin;
	
	}
	else if (strcmp(mod, "w") == 0) {
		if (argc <= poradi ||
				strcmp(argv[poradi], "--") == 0)
			return stdout;
		
	}
	else 
		return NULL;

	return fopen(argv[poradi], mod);
}


int main(int argc, char **argv) {

	FILE *in = parametr(1, "r", argc, argv);
	FILE *out = parametr(2, "w", argc, argv);


	if (in == NULL || out == NULL) {
		printf("Wrong input parameters!\n"
			   "Run like this: clang main.c;./a.out exams.txt students_results.txt\n"
			   " - if first parameter won't be chosen it will be stdin\n"
			   " - if second parameter won't be chosen it will be stdout\n"
				);
		return 1;
	}

	vysledky(in, out, "ABCDABCDAB");


	if (in != stdin) fclose(in);
	if (out != stdout) fclose(out);

	return 0;
}
