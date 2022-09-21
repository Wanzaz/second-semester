#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	int grade1, grade2, grade3;
} TStudent;

void worstGrade(FILE *input, FILE *output);

int main(int argc, char **argv) {

	if (argc != 3) {
		fprintf(stderr, "Run like this: gcc main.c; ./a.out inputfile outfile\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];
	char *outputpath = argv[2];

	FILE *file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!", inputpath);
		return EXIT_FAILURE;
	}

	FILE *result = fopen(outputpath, "w");
	if (result == NULL) {
		fprintf(stderr, "Output file %s is unable to open!", outputpath);
		return EXIT_FAILURE;
	}

	worstGrade(file, result);

	fclose(file);
	fclose(result);

	return 0;
}


void worstGrade(FILE *input, FILE *output) {
	TStudent student;

	while(fscanf(input, "%29s%d%d%d", student.name, &student.grade1, &student.grade2, &student.grade2) == 4) {
		int worst_grade;
		if (student.grade1 > student.grade2)	
			worst_grade = student.grade1;
		else
			worst_grade	= student.grade1;
		if (student.grade3 > worst_grade)	
			worst_grade = student.grade3;
		fprintf(output, "Name: %s, Worst grade: %d\n", student.name, worst_grade);
	}
}
