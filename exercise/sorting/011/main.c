#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define SWAP(T, A, B) ({ T h = A; A = B; B = h; })

typedef struct _person {
    char name[20+1];
    int age;
} Tperson;

typedef struct _array {
    Tperson *value;
    int length;
} TArrayOfPeople;

TArrayOfPeople * loadPeople(FILE *file) {
    TArrayOfPeople * array = malloc(sizeof(TArrayOfPeople));
    if (array == NULL) return NULL;

#define BLOCK 32
    array->value= NULL;
    array->length = 0;
    int index = 0;

    Tperson person;

    while(fscanf(file, "%20s %d", person.name, &person.age) == 2) {
        if (index == array->length) {
            array->length += BLOCK;
            Tperson * temp = realloc(array->value, array->length*sizeof(Tperson));
            if (temp == NULL) {
                return array;
            }
            array->value = temp;
        }
        array->value[index++] = person;
    }

    array->value = realloc(array->value, index*sizeof(Tperson));
    array->length = index;
    return array;
}


TArrayOfPeople * loadPeople100(FILE *file) {
    TArrayOfPeople * array = malloc(sizeof(TArrayOfPeople));
    if (array == NULL) return NULL;
    array->value = malloc(MAXN*sizeof(Tperson));
    if (array->value == NULL) {
        free(array); return NULL;
    }
    int index = 0;
    while(index < MAXN && fscanf(file, "%20s %d", array->value[index].name, &array->value[index].age) == 2) {
        index += 1;
    }

    array->length = index;
    return array;
}

// TODO: replace by macro
static inline
void swap(Tperson *array, int a, int b) {
    Tperson temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void sortArray(TArrayOfPeople *people, int pivot) {
    int left = 0;
    int right = people->length - 1;
    while(left < right)
    {
        while(left < right && people->value[left].age < pivot) left++;
        while(left < right && people->value[right].age >= pivot) right--;

        if (left >= right) return;

        /* SWAP(Tperson , people->value[left], people->value[right]); */
        /* left++, right--; */
        swap(people->value, left++, right--);
    }
}

void writingArray(FILE * file, TArrayOfPeople * people) {
    rewind(file);

    for (int index = 0; index < people->length ; ++index) {
        fprintf(file, "%s %d\n", people->value[index].name, people->value[index].age);
    }
}

void sortFile(FILE *file, int pivot) {
    TArrayOfPeople * people = loadPeople(file);
    if (people == NULL) return;

    sortArray(people, pivot);
    writingArray(stdout, people);
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Run like this: clang main.c; ./a.out inputfile pivot\n");
        return EXIT_FAILURE;
    }

    char *inputpath = argv[1];
    char *arg_pivot = argv[2];
    int pivot;
    sscanf(arg_pivot, "%i", &pivot);

    FILE * file = fopen(inputpath, "r+");
    sortFile(file, pivot);

    fclose(file);

    return 0;
}
