#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} Tperson;

Tperson * hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void printHashTable()
{
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i,  hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hashTableInsert(Tperson *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL) {
        return false;
    }
    hash_table[index] = p;
    return true;
}

Tperson *hashTableLookup(char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            return hash_table[index];
    } else {
        return NULL;
    }
}

Tperson *hashTableDelete(char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            Tperson *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
    } else {
        return NULL;
    }
}


int main(int argc, char *argv[])
{
    initHashTable();
    printHashTable();

    Tperson jacob = {.name = "Jacob", .age = 256};
    Tperson kate = {.name = "Kate", .age = 27};
    Tperson mpho = {.name = "Mpho", .age = 14};

    hashTableInsert(&jacob);
    hashTableInsert(&kate);
    hashTableInsert(&mpho);
    printHashTable();

    hashTableDelete("Mpho");
    Tperson *tmp = hashTableLookup("Mpho");
    if (tmp == NULL) {
        printf("Not Found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
    
    tmp = hashTableLookup("George");
    if (tmp == NULL) {
        printf("Not Found\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }


    return 0;
}

