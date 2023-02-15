#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct person
{
    char name[21];
    int age;
    bool occupied;
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

void insertPerson(ThashMap *hashmap)
{
    printf("Enter a name and a age: ");
    Tperson person;
    scanf("%20s %i", person.name, &person.age);
    person.occupied = true;
    insertHmap(hashmap, person);
}

void removePerson(ThashMap * hashmap)
{
    printf("Enter a name: ");
    char name[21];
    scanf("%20s", name);
    Tperson person;
    if (!findHmap(hashmap, name, &person)) {
        printf("Not Found\n");
        return;
    }

    removeHmap(hashmap, person.name);
    printf("%s removed\n", person.name);
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

void pause(void)
{
    #if defined __WIN32 || defined __WIN64
        system("pause"); 
	#else 
		system("read a");
	#endif
}

void clear(void)
{
	#ifdef _WIN32 
		system("cls");
	#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	    system("clear");
	//add some other OSes here if needed
	#else
		#error "OS not supported."
	#endif
}

void menu(void)
{
    clear();
    printf("HASHMAP\n"
           "0..............................exit\n"
           "1...............Insert a new person\n"
           "2.....Remove a person by their name\n"
           "3.......Find a person by their name\n"
           "4...............Write out everybody\n"
            );

}

void end(ThashMap * hashmap)
{
    exit(0);
}

const int sizeOfAction = 3;
const Action action[] = {
    { "end", end },
    { "insert", insertPerson },
    { "remove", removePerson },
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
        menu();
        int actionOfIndex;
        printf("Choose a number: ");
        scanf("%i", &actionOfIndex);
        action[actionOfIndex].function(&hashmap);

        if (actionOfIndex != 0 && actionOfIndex != 1) {
            pause();
        }
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
