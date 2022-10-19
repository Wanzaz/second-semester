#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
	char name[21];
	char class[5];
	int grade1, grade2, grade3;

} Tstudent;

int countStudents(FILE *input, Tstudent a[], int max_size) {
	int i=0;
	
	while (i < MAX && fscanf(input, "%20s%4s%d%d%d", a[i].name, a[i].class, &a[i].grade1, &a[i].grade2, &a[i].grade3) == 5) {
		i++;
	}

	return i;
}

void listStructure(FILE *output, Tstudent array[], int size) {
	for (int i=0; i < size; i++) {
		fprintf(output, "%s %s %d %d %d\n", array[i].name, array[i].class, array[i].grade1, array[i].grade2, array[i].grade3);
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

	int size = countStudents(file, array, MAX);
	printf("Number of students: %d\n", size);
	listStructure(stdout, array, size);


	fclose(file);

	return 0;
}
