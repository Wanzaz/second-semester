#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool read(FILE *file, int *element)
{
    return (fscanf(file, "%d", element) == 1);
}

bool write(FILE *file, int element)
{
    return fprintf(file, "%d ", element);
}

void mergeTwoSortedFiles(FILE *inputa, FILE *inputb, FILE *output) 
{
    int a, b;

    bool aokay = read(inputa, &a);
    bool bokay = read(inputb, &b);

    while (aokay && bokay) {
        if (a <= b) {
            write(output, a);
            aokay = read(inputa, &a);
        } else {
            write(output, b);
            bokay = read(inputb, &b);
        }
    }

    while (aokay) {
        write(output, a);
        aokay = read(inputa, &a);
    }

    while (bokay) {
        write(output, b);
        bokay = read(inputb, &b);
    }

}

int main (void) 
{
    FILE *numbers1 = fopen("numbers1.txt", "r");
    FILE *numbers2 = fopen("numbers2.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (numbers1 == NULL || numbers2 == NULL || output == NULL) {
        return EXIT_FAILURE;
    }

    mergeTwoSortedFiles(numbers1, numbers2, output);

    fclose(numbers1);
    fclose(numbers2);
    fclose(output);
    return 0;
}
