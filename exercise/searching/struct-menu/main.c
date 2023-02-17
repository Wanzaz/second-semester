#include<stdio.h>
#include<stdbool.h>

// This code is written by Majkl

typedef int T;

typedef struct {
    char *name;
    bool onSorted;
    int (*function)(T[], int, T);
} SearchAlgorithm;

bool equals(T x, T y)
{
    return x == y;
}

bool smallerThan(T x, T y)
{
    return x < y;
}

int load(FILE* from, T numbers[], T size)
{
    int i = 0;
    while (i < size && fscanf(from, "%i", &numbers[i]) == 1) {
        i++;
    }
    return i;
}

int sequentialSearch(T numbers[], int size, T key)
{
    int i = 0;
    for (; i < size && !equals(numbers[i], key); i++) { }
    return i < size ? i : -1;
}

int sequentialSearchWithBreak(T numbers[], int size, T key)
{
    numbers[size] = key;
    int i = 0;
    for (; !equals(numbers[i], key); i++) { }
    return i < size ? i : -1;
}

int sequentialSearchOnSorted(T numbers[], int size, T key)
{
    int i = 0;
    for (; i < size && smallerThan(numbers[i], key); i++) { }
    return i < size && equals(numbers[i], key) ? i : -1;
}

int sequentialSearchOnSortedWithBreak(T numbers[], int size, T key)
{
    int i = 0;
    numbers[size] = key;
    for (; smallerThan(numbers[i], key); i++) {}
    return i < size && equals(numbers[i], key) ? i : -1;
}

int _binarySearch(T numbers[], int from, int to, T key)
{
    if (from > to) {
        return -1;
    }

    int middle = (to + from) / 2;

    if (equals(numbers[middle], key)) {
        return middle;
    }

    if (smallerThan(key, numbers[middle])) {
        return _binarySearch(numbers, from, middle - 1, key);
    }
    
    return _binarySearch(numbers, middle + 1, to, key);
}

int binarySearch(T numbers[], int size, int key)
{
    return _binarySearch(numbers, 0, size - 1, key);
}

#define SEARCH_COUNT 5
const SearchAlgorithm algorithms[] = {
    { "sequence search", false, sequentialSearch },
    { "sequence search with break", false, sequentialSearchWithBreak },
    { "sequence search on sorted array", true, sequentialSearchOnSorted },  
    { "sequence search on sorted array with break", true, sequentialSearchOnSortedWithBreak },
    { "binary search", true, binarySearch }
};

bool sorted(int numbers[], int size)
{
    for (int index = 0; index < size - 1; index++) {
        if (numbers[index] > numbers[index + 1]) {
            return false;
        }
    }

    return true;
}

void put(int numbers[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%i ", numbers[i]);
    }
}

void sort(int numbers[], int size)
{
    int inner;
    int current;
    for (int index = 1; index < size; index++) {
        inner = index;
        current = numbers[index];
        while (inner > 0 && numbers[inner - 1] > current) {
            numbers[inner] = numbers[inner - 1];
            inner--;
        }
        numbers[inner] = current;
    }
}

void searchMenu(int numbers[], int size, int key)
{
    printf(
        "Searching\n\n"
        "0. end\n"
    );
    for (int i = 0; i < SEARCH_COUNT; i++) {
        printf("%i, %s\n", i + 1, algorithms[i].name);
    }

    int action;
    scanf("%i", &action);

    if (action == 0) {
        return;
    }

    SearchAlgorithm algorithm = algorithms[action - 1];

    if (algorithm.onSorted && !sorted(numbers, size)) {
        sort(numbers, size);
    }

    printf("position: %i\n", algorithm.function(numbers, size, key));
}

int main(void)
{
    FILE* f = fopen("numbers.txt", "r");
    if (f == NULL) {
        return -1;
    }
    int key;
    printf("Enter a key that you wanna find: ");
    scanf("%i", &key);
    int numbers[7001]; // Break
    int size = load(f, numbers, 7000);
    searchMenu(numbers, size, key);
    fclose(f);
}
