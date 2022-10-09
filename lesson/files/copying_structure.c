#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
	char name[21];
	int m, p, ch, pr;

} Tstudent;

int countStudents(FILE *input, Tstudent a[]) {
	int i=0;
	
	while (i < MAX && fscanf(input, "%20s%d%d%d%d", a[i].name, &a[i].m, &a[i].p, &a[i].ch, &a[i].pr) == 5) {
		i++;
	}

	return i;
}

void listStructure(Tstudent array[], int size) {
	for (int i=0; i < size; i++) {
		printf("%s m: %d, p: %d, ch: %d, pr: %d\n", array[i].name, array[i].m, array[i].p, array[i].ch, array[i].pr);
	}
}

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: gcc students.c; ./a.out inputfile\n");
		return EXIT_FAILURE;
	}

	Tstudent array[MAX];
	char *inputpath = argv[1];

	FILE* file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", inputpath);
		return EXIT_FAILURE;
	}

	int size = countStudents(file, array);
	printf("Number of students: %d\n", size);
	listStructure(array, size);


	fclose(file);

	return 0;
}

