#include <stdio.h>
#include <stdlib.h>
/* #include <string.h> */

#define MAX 1000

typedef struct {
	char name[21];
	char class[5];
	int grade1, grade2, grade3;

} Tstudent;

typedef struct {
	Tstudent value[MAX];
	int size;
} TArray;

int countStudents(FILE *input, TArray *array, int max_size) {
	int i = 0;
	
	while (i < max_size && fscanf(input, "%20s%4s%d%d%d", array->value[i].name, array->value[i].class, &array->value[i].grade1, &array->value[i].grade2, &array->value[i].grade3) == 5) {
		i++;
	}

	return i;
}

void listStructuralArray(FILE *output, TArray array, int size) {
	for (int i = 0; i < size; i++) {
		fprintf(output, "%s %s %d %d %d\n", array.value[i].name, array.value[i].class, array.value[i].grade1, array.value[i].grade2, array.value[i].grade3);
	}
}

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile\n");
		return EXIT_FAILURE;
	}

	TArray array;
	char *inputpath = argv[1];

	FILE* file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", inputpath);
		return EXIT_FAILURE;
	}

	int size = countStudents(file, &array, MAX);
	printf("Number of students: %d\n", size);
	listStructuralArray(stdout, array, size);


	fclose(file);

	return 0;
}
