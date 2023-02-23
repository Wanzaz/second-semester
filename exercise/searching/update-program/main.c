#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct
{
    int id;
    char name[21];
    char lastname[21];
    int age;
    char profession[21];
    char country[21];
    int salary;
    bool removed; // true removed, false not removed
} Tperson;


int load(FILE *input, Tperson a[], int max_length)
{
    int i = 0;
    while(i < max_length && 
            fscanf(input, "%d %20s %20s %d %20s %20s %d",
                &a[i].id,
                a[i].name,
                a[i].lastname,
                &a[i].age,
                a[i].profession,
                a[i].country,
                &a[i].salary) == 7)
    {
        a[i].removed = false;
        i++;
    }

    return i;
}

/* int searchID(Tperson array[], int length, int searchedID) */
/* { */
/*     int left = 0; */
/*     int right = length - 1; */

/*     while (left <= right) { */
/*         int middle = (left + right) / 2; */

/*         if (array[middle].id == searchedID) { */
/*             return middle; */
/*         } */
/*         if (array[middle].id < searchedID) { */
/*             left = middle + 1; */
/*         } else { */
/*             right = middle - 1; */
/*         } */
/*     } */

/*     return -1; */
/* } */

/* int seqSortSearch(Tperson array[], int n, int key) */
/* { */
/*     int i = 0; */
    
/*     while (i < n && array[i].id < key) { */
/*         i++; */
/*     } */

/*     if (i < n && array[i].id == key) return i; */
/*     else return -1; */
/* } */

int _find(Tperson array[], int left, int right, int searchedID)
{
    if (left > right) return -1;
    
    int middle = (left + right) / 2;

    if (array[middle].id == searchedID) {
        return middle;
    }
    if (array[middle].id < searchedID) {
        return _find(array, middle + 1, right, searchedID);
    }
    else {
        return _find(array, left, middle - 1, searchedID);
    }
}

int find(Tperson array[], int n, int searchedID)
{
    return _find(array, 0, n - 1, searchedID);
}


enum CHANGES {CHANGE=0, NEW=1, REMOVE=-1};

int changes(Tperson array[], int length, int max_length, FILE *input)
{
    Tperson temp;
    int operation;
    int found;

    while (fscanf(input, 
            "%d %20s %20s %d %20s %20s %d %d",
                &temp.id,
                temp.name,
                temp.lastname,
                &temp.age,
                temp.profession,
                temp.country,
                &temp.salary,
                &operation) == 8) {

        found = find(array, length, temp.id);

        switch(operation) {
            case REMOVE:
                if (found >= 0) {
                    array[found].removed = true;
                }
                break;

            case CHANGE:
                if (found >= 0) {
                    array[found] = temp;
                    array[found].removed = false;
                }
                break;

            case NEW:
                if (temp.id == 0) {
                    int newIndex = length;
                    length +=1;
                    int newID = (newIndex == 0) ? 0 : array[newIndex - 1].id + 1;
                    temp.id = newIndex;
                    array[newIndex] = temp;
                    array[newIndex].removed = false;
                }
                break;
        }
    }

    return length;
}

void write(FILE *output, Tperson a[], int length)
{
    for(int i = 0; i < length; i++) {
        if(!a[i].removed) {
            fprintf(output, "%d %s %s %d %s %s %d\n",
                a[i].id,
                a[i].name,
                a[i].lastname,
                a[i].age,
                a[i].profession,
                a[i].country,
                a[i].salary);
        }
    }
}

int main()
{
    FILE *fchanges, *data;
    Tperson array[MAX_LENGTH];
    int n;

    fchanges = fopen("changes.txt", "r");
    data = fopen("data.txt", "r");
    if (fchanges == NULL || data == NULL) {
        fprintf(stderr, "Files cannot be opened!");
        return -1;
    }

    n = load(data, array, MAX_LENGTH);
    n = changes(array, n, MAX_LENGTH, fchanges);

    fclose(data);

    data = fopen("result.txt", "w");
    if (data == NULL) {
        fprintf(stderr, "Files cannot be opened!");
        return -1;
    }

    write(data, array, n);


    fclose(fchanges);
    fclose(data);

    return 0;
}
