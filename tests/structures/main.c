#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char name[21];
    char gender[21];
    int maths;
    int physics;
    int pe;

} Tstudent;


int load(FILE *input, Tstudent a[], int max_length) 
{
    int i = 0;
    while(i < max_length && 
            fscanf(input, "%20s %20s %d %d %d",
                a[i].name,
                a[i].gender,
                &a[i].maths,
                &a[i].physics,
                &a[i].pe)== 5) {
        i++;
    }

    return i;
}

void printOut(FILE *output, Tstudent a[], int length) 
{
    for(int i = 0; i < length; i++) {
        fprintf(output, "%s %s %d %d %d\n",
            a[i].name,
            a[i].gender,
            a[i].maths,
            a[i].physics,
            a[i].pe);
    }
}

int indexOfFirstBoy(Tstudent a[], int length) {
    for(int i = 0; i < length - 1; i++) {
        if(!strcmp(a[i].gender, "kluk")) {
            return i;
        }
    }
    return -1;
}

int findStudentIndex(Tstudent a[], int length, int first_boy_index) {
    int worst_grade_physics = a[first_boy_index].physics;
    printf("%d", worst_grade_physics);
    int index;

    for (int i = first_boy_index + 1; i < length; i++) {
        if (!strcmp(a[i].gender, "kluk")) {
            if (worst_grade_physics < a[i].physics) {
                worst_grade_physics = a[i].physics;
                index = i;
            }
        }
    }

    return index;
}

int main(int argc, char *argv[])
{
   Tstudent array[MAX];

    FILE *fstudents = fopen("students.txt", "r");
    if (fstudents == NULL) {
        printf("File cannot be opened\n");
        return -1;
    }

    int actual_length = load(fstudents, array, MAX);
    printf("Number of students: %d\n", actual_length);

    printOut(stdout, array, actual_length);

    int first_boy = indexOfFirstBoy(array, actual_length);
    printf("First boy index: %d\n", first_boy);


    int index_worst_student = findStudentIndex(array, actual_length, first_boy);

    printf("The worst physics student is: %s\n", array[index_worst_student].name);
    printf("The worst physics mark is: %d\n", array[index_worst_student].physics);



    
    fclose(fstudents);

    return 0;
}
