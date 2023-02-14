#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct person
{
    char name[21];
    int age;
    bool occupied;
    struct person *next;
} Tperson;

typedef struct
{
    Tperson *array;
    int length;

} ThashMap;

typedef struct
{
    char *text;
    void (*function)(ThashMap *hashmap);
} Action;

void writeOutPerson(Tperson *person)
{
    printf("%s %i\n", person->name, person->age);
    if (person->next) {
        writeOutPerson(person->next);
    }
}

void writeOutMap(ThashMap *hashmap)
{
    for(int i = 0; i < hashmap->length; i++) {
        if (hashmap->array[i].occupied) {
            writeOutPerson(&hashmap->array[i]);
        }
    }
}

void init(ThashMap *hashmap)
{
    for(int i = 0; i < hashmap->length; i++) {
        hashmap->array[i].occupied = false;
    }
}

int hashFunction(char name[], ThashMap *hashmap)
{
    int result = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        result += name[i];
    }

    return result % hashmap->length;
}


int insertHmap(ThashMap *hashmap, Tperson person)
{
    int hash = hashFunction(person.name, hashmap);
    hashmap->array[hash] = person;
    return hash;
}

int removeHmap(ThashMap *hashmap, char name[])
{
    int hash = hashFunction(name, hashmap);
    hashmap->array[hash].occupied = false;
    return hash;
}

int findHmap(ThashMap *hashmap, char name[], Tperson *person)
{
    int hash = hashFunction(name, hashmap);
    *person = hashmap->array[hash];
    return hashmap->array[hash].occupied;
}

void insert(ThashMap *hashmap)
{
    printf("Enter a name and a age: ");
    Tperson person;
    scanf("%20s %i", person.name, &person.age);
    person.occupied = true;
    insertHmap(hashmap, person);
}

void getPerson(ThashMap * hashmap)
{
    printf("Enter a name: ");
    char name[21];
    scanf("%20s", name);
    Tperson person;
    if (!findHmap(hashmap, name, &person)) {
        printf("Not Found\n");
        return;
    }

    writeOutPerson(&person);
}

void end(ThashMap * hashmap)
{
    exit(0);
}

const int sizeOfAction = 3;
const Action action[] = {
    { "end", end },
    { "insert", insert },
    { "get", getPerson },
    { "write out everything", writeOutMap },
};


int main(void)
{
    int max = 100;
    Tperson *array = (Tperson *) malloc(sizeof(Tperson) * max);

    ThashMap hashmap;
    hashmap.array = array;
    hashmap.length = max;

    init(&hashmap);

    while (1) {
        int actionOfIndex;
        printf("Enter a number: ");
        scanf("%i", &actionOfIndex);
        action[actionOfIndex].function(&hashmap);
    }

    free(array);

    return 0;
}


// How does pointer works? - Explanation
/* fce(typ * p ) { */
/*     p->slozka = ... */
/* } */

/* typ p; */
/* fce(&p); */

/* p*p = malloc(sizeof(typ p)) */
/*     fce(p) */
