#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TUPLEOFTWO 2


bool readElement(FILE *file, int *element)
{
    return (fscanf(file, "%d", element) == 1);
}

bool writeElement(FILE *file, int element)
{
    return fprintf(file, "%d ", element);
}

bool tryToRead(FILE *tape, int limit, int *element, int *plural_read) 
{
    // reads only inside the block given between
    bool read = (*plural_read < limit) && (readElement(tape, element) == 1);

    if (read) plural_read++;

    return read;
}

int mergeSection(int section_length, FILE *tape, FILE *temp1, FILE *temp2) 
{
    // length section is tuple (2)
    int written = 0;
    int elements1 = 0;
    int elements2 = 0;

    int element1;
    int element2;

    bool inside1 = tryToRead(temp1, section_length, &element1, &elements1);
    bool inside2 = tryToRead(temp2, section_length, &element2, &elements2);


    while (inside1 && inside2) {
        if (element1 <= element2) {
            writeElement(tape, element1);
            inside1 = tryToRead(temp1, section_length, &element1, &elements1);
        } else {
            writeElement(tape, element2);
            inside2 = tryToRead(temp2, section_length, &element2, &elements2);
        }

        written++;
    }

    while (inside1) {
        writeElement(tape, element1);
        written++;
        inside1 = tryToRead(temp1, section_length, &element1, &elements1);
    }

    while (inside2) {
        writeElement(tape, element2);
        written++;
        inside2 = tryToRead(temp2, section_length, &element2, &elements2);
    }

    return written;
}


int main () 
{
    FILE *numbers1 = fopen("numbers1.txt", "r");
    FILE *numbers2 = fopen("numbers2.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (numbers1 == NULL || numbers2 == NULL || output == NULL) {
        return EXIT_FAILURE;
    }

    int number_of_written_nums = mergeSection(TUPLEOFTWO, output, numbers1, numbers2);
    printf("%d\n", number_of_written_nums);

    fclose(numbers1);
    fclose(numbers2);
    fclose(output);
    return 0;
}
