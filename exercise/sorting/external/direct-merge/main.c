#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool readElement(FILE *file, int *element)
{
    return (fscanf(file, "%d", element) == 1);
}


bool writeElement(FILE *file, int element)
{
    return fprintf(file, "%d ", element);
}


int reset(FILE *tape)
{
    fclose(tape);
    tape = tmpfile();
    if (tape == NULL) return EXIT_FAILURE;

    return 0;
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


bool divide(FILE *tape, FILE *a, FILE *b, int section_length)
{
    int counter = section_length;
    int written = 0;
    FILE *temp = a;
    int first = true;
    int element;
    rewind(tape);
    
    while (readElement(tape, &element)) {
        if (counter == 0) {
            counter = section_length;
            temp = (first) ? b : a; // at the end -> swap tape
            first = !first; // reading from second tape
        }
        writeElement(temp, element), --counter, ++written;
    }
    return (section_length < written);
}

bool merge(int section_length, FILE *tape, FILE *a, FILE *b)
{
    int total = 0;
    int written = 0;
    rewind(tape), rewind(a), rewind(b);

    do {
        written = mergeSection(section_length, tape, a, b);
        total += written;

    } while (written == 2 * section_length);
    
    
    return (2 * section_length) < total;
}


int directMerge(FILE *tape)
{
    int section_length = 1;
    FILE *a = fopen("output1.txt", "w");
    FILE *b = fopen("output2.txt", "w");

    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }

    while (divide(tape, a, b, section_length) && merge(section_length, tape, a, b)) {
        section_length *= 2;
        /* rewind(a); rewind(b); */ // RESET
        reset(a), reset(b);
    }
    fclose(a); fclose(b);

    return 0;
}


int main () 
{
    FILE *input = fopen("numbers.txt", "r+");


    directMerge(input);


    fclose(input);
    return 0;
}
