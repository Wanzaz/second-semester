#include <stdio.h>
#include <stdlib.h>

#define SWAP(T, A, B) do { T h = A; A = B; B = h; } while(0)

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
    #define MAXN 100
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

// REPLACED BY THE MACRO
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
        while(left < right && people->value[left].age <= pivot) left += 1;
        while(left < right && people->value[right].age > pivot) right -= 1;

        if (left >= right) return;

        SWAP(Tperson , people->value[left++], people->value[right--]); // left++, right-- could be a problem
		/* swap(people->value, left++, right--); */
    }
}

void writingArray(FILE * file, TArrayOfPeople * people) {
    rewind(file);

    for (int index = 0; index < people->length ; ++index) {
        fprintf(file, "%s %d\n", people->value[index].name, people->value[index].age);
    }
}

void roztridSoubor(FILE *file, int pivot) {
    TArrayOfPeople * people = loadPeople(file);
    if (people == NULL) return;

    sortArray(people, pivot);
    writingArray(file, people);
}


int main(void) {
    printf("Enter name of a file: ");
    char path[255+1];
    scanf("%255s", path);

    printf("Enter a value of a pivot: ");
    int pivot;
    scanf("%d", &pivot);

    FILE * file = fopen(path, "r+");
    roztridSoubor(file, pivot);

    fclose(file);
	return 0;
}

