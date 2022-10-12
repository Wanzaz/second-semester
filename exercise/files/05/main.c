#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
	char name[21];
	char class[5];
	int theory_grade, practise_grade;
	float average_grade;
} TStudent;


void divideInClasses(FILE *input, char *name_class1, FILE *class1, char *name_class2, FILE *class2) {
	TStudent student;
	int	count_of_grades = 0;

	while (fscanf(input, "%20s%4s%d%d", student.name, student.class, &student.theory_grade, &student.practise_grade) == 4) {
		if (strcmp(student.class, name_class1) == 0) {
			count_of_grades = student.practise_grade + student.theory_grade;
			fprintf(class1, "%s %.1f\n", student.name, count_of_grades/2.0);
		}
		else if (strcmp(student.class, name_class2) == 0) {
			count_of_grades = student.practise_grade + student.theory_grade;
			fprintf(class2, "%s %.1f\n", student.name, count_of_grades/2.0);
		}
		else {
			fprintf(stdin, "Student: %s isn't in any class.\n", student.name);
		}
		count_of_grades = 0;
	}
}

void gradeAverage(FILE *input) {
	TStudent student;
	float sum_practise = 0.0;
	float sum_theory = 0.0;
	int num_of_students = 0;
	rewind(input);

	while (fscanf(input, "%20s%4s%d%d", student.name, student.class, &student.theory_grade, &student.practise_grade) == 4) {
		num_of_students += 1;
		sum_theory += student.theory_grade;
		sum_practise += student.practise_grade;
	}

	printf("Average theory grade: %.1f\nAverage practise grade: %.1f\n", sum_theory/num_of_students, sum_practise/num_of_students);
}

void whoFailed(FILE *input, FILE *failed_student) {
	TStudent student;
	while (fscanf(input, "%20s%f", student.name, &student.average_grade) == 2) {
		if (student.average_grade >= 4.5) {
			fprintf(failed_student, "%s %.1f\n", student.name, student.average_grade);
		}
	}

}


int main(int argc, char **argv) {

	if (argc != 7) {
		fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile name_of_class1 class1 name_of_class2 class2 failed_students_file\n");
		return EXIT_FAILURE;
	}

	char *inputpath = argv[1];
	char *name_of_class1 = argv[2];
	char *class1_path = argv[3];
	char *name_of_class2 = argv[4];
	char *class2_path = argv[5];
	char *failed_students_path = argv[6];

	FILE *students = fopen(inputpath, "r");
	if (students == NULL) {
		fprintf(stderr, "%s file is unable to open!\n", inputpath);
	}

	FILE *class_1 = fopen(class1_path, "w+");
	if (class_1 == NULL) {
		fprintf(stderr, "%s file is unable to open\n!", class1_path);
	}

	FILE *class_2 = fopen(class2_path, "w+"); // read and write
	if (class_2 == NULL) {
		fprintf(stderr, "%s file is unable to open!\n", class2_path);
	}

	FILE *failed_students = fopen(failed_students_path, "w"); // read and write
	if (failed_students == NULL) {
		fprintf(stderr, "%s file is unable to open!\n", failed_students_path);
	}

	divideInClasses(students, name_of_class1, class_1, name_of_class2, class_2);
	gradeAverage(students);
	rewind(class_1);
	rewind(class_2);

	whoFailed(class_1, failed_students);
	whoFailed(class_2, failed_students);
	


	fclose(students);
	fclose(class_1);
	fclose(class_2);
	fclose(failed_students);

	return 0;
}

