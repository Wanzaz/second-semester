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

/* int loadStructureToArray(FILE *input, Tstudent a[]) { */
/* 	int i=0; */
	
/* 	while (i < MAX && fscanf(input, "%20s%d%d%d%d", a[i].name, &a[i].m, &a[i].p, &a[i].ch, &a[i].pr) == 5) { */
/* 		i++; */
/* 		a[i] = strcpy(a[i], a[i].name); */
/* 	} */

/* 	return i; */
/* } */


/* void listArray(int array) { */
	

/* } */

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Run like this: program option inputfile outputfile\n");
		return EXIT_FAILURE;
	}

	Tstudent array[MAX];
	char *inputpath = argv[1];

	FILE* file = fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr, "Input file %s is unable to open!\n", inputpath);
		return EXIT_FAILURE;
	}

	int result = countStudents(file, array);
	printf("Number of students: %d\n", result);


	fclose(file);

	return 0;
}

