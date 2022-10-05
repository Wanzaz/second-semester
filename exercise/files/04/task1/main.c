#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	double payment;
} TPerson;

void payment(FILE *input, FILE *output);

int main(int argc, char **argv) {

	if (argc != 3) {
		fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile outfile\n");
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

	payment(file, result);

	fclose(file);
	fclose(result);

	return 0;
}


void payment(FILE *input, FILE *output) {
	TPerson person;
	int highest_payment, lowest_payment;
	char hig_name[30], low_name[30];

	if (fscanf(input, "%29s%lf", person.name, &person.payment) == 2) {
		highest_payment = person.payment;
		lowest_payment = person.payment;
		strcpy(hig_name, person.name);
		strcpy(low_name, person.name);
	}

	while(fscanf(input, "%29s%lf", person.name, &person.payment) == 2) {

		if (person.payment > highest_payment) {
			highest_payment = person.payment;
			strcpy(hig_name, person.name);
		}
		if (person.payment < lowest_payment) {
			lowest_payment = person.payment;
			strcpy(low_name, person.name);
		}

		double fifteen_more = person.payment > 0 
			? person.payment * 1.15 
			: -person.payment * 0.15 + person.payment;

		fprintf(output,"%s %.0lf\n", person.name, fifteen_more);
	}
	printf("Highest pay: %d, Person: %s \nLowest pay: %d, Person: %s\n", highest_payment, hig_name, lowest_payment, low_name);
}
