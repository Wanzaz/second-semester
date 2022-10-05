#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char grade1, grade2, grade3;
} TStudent;

void averageGrades(FILE *input);

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: gcc main.c; ./a.out inputfile\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];

	FILE *file = fopen(inputpath, "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!", inputpath);
		return EXIT_FAILURE;
	}

	averageGrades(file);

	fclose(file);

	return 0;
}


void averageGrades(FILE *input) {
	TStudent student;
	double math, physics, programming;
	int number_of_grades;

	while(fscanf(input, "%c%c%c ", &student.grade1, &student.grade2, &student.grade3) == 3) {
		number_of_grades++;
		math += student.grade1 - '0';
		/* printf("%f", math); */
		physics += student.grade2 - '0';
		programming += student.grade3 - '0';
	}

	printf("Average grade in math: %.2f, physics: %.2f, programming: %.2f\n", math / number_of_grades, physics / number_of_grades, programming / number_of_grades);
}
