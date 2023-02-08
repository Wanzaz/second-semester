#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

# define MAXN 100

typedef struct
{
    char name[21];
    int age;
    bool occupied;
} Telement;

typedef struct
{
    Telement *value;
    int n;

} ThashMap;

ThashMap loadElements(int length) {
    /* map = malloc(sizeof(ThashMap)); */
    ThashMap map;

    map.value = malloc(length*sizeof(Telement));

    map.n = length;

    return map;
}

void writeOut (ThashMap *hashmap, int n)
{
    for(int i = 0; i < n - 1; i++) {
        if (hashmap->value[i].occupied == false) { // FIXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
            printf("Name: %s Age: %d\n", hashmap->value[i].name, hashmap->value[i].age);
        }
    }
    /** Pohlidejte si, ze obsazeno je 1, 0 totiz znamena, ze polozka neexistuje, podle toho vypisujte,
        tzn. vypisujete pouze pole, kde obsazeno je 1. **/
}


void init(ThashMap *hashmap, int n)
{
    for(int i = 0; i < n - 1; i++) {
        hashmap->value[i].occupied = false;
    }
}


int hash(ThashMap *hashmap, Telement person)
{
    /** vrati bud upraveny vek (podle delky pole) nebo totalni cif soucet, nebo jednotky, nebo udelejte vlastni hashfunkci podle delky pole*/
    int sum;
    int length = strlen(person.name);
    for(int i = 0; i < length; i++) {
        sum += person.name[i];

    }

    return sum % length;
}


/******** Vloz do tabulky *******/
int insertHmap(ThashMap * hashmap, int n, Telement person)
{
   /** dopln (viz Classroom str. 35)**/
    int index = hash(hashmap, person);
    hashmap->value[index] = person;
    hashmap->value[index].occupied = true;
}

/******** Vymaz z tabulky *******/
int removeHmap(/**dopln pole, delku, vek podle ktereho odebirame**/)
{
    /**dopln (viz Classroom str. 36)**/
}

/******** Najdi v tabulce *******/
int findHmap(/**dopln pole, delku, co vkladme: datovy typ osoba**/)
{
    /**dopln (viz Classroom str. 37)**/
    /** Pohlidejte si, ze obsazeno je 1, 0 totiz znamena, ze polozka neexistuje, podle toho vypisujte **/
}



/******** MAIN ******************************************************/
int main(void)
{
    /** 1. Vytvor osoba pole[10] + dalsi pomocne promenne, popr. pole jine delky pokud chcete**/ 
    int array[MAXN];


    /** 3. Zavolej inicializaci pole: funkci init (chceme vsechny pole nastavit na obsazeno = 0) **/

       // dopln

    /** 4. Do pole bude uzivatel zadavat osoby: jmeno a vek, a to tak dlouho, dokud uzivatel nezada nesmyslny vek, tj.
           napriklad zaporny. **/
    int age;
    printf("Enter a name: ");
   // dopln
    printf("Enter a age: ");
  //  dopln
    while(0 < age)
    {
      /**  zavolejte funkci vlozHtab a pridejte novou osobu**/
        printf("Zadej jmeno: ");
      //  dopln
        printf("Zadej vek: ");
      //  dopln
    }


/** 3. Zavolejte funkci vypis **/

    //dopln


/** 4. Zavolejte funkci pro vyhledani osoby ... vyhledavame podle veku **/

    printf("Enter a age of person, who we search: ");
   // dopln
  /**  zavolej funkci najdiHtab
    vypis jmeno osoby, pokud existuje (obsazeno == 1), jinak vypis, ze takova osoba neni**/

/** 5. Zavolejte funkci pro odebrani nejake osoby ... odebirame osobu podle jejiho veku **/

    printf("Enter a age of person, who we remove: ");
    //dopln
    //zavolej funkci vymazHtab

/** 6. Zavolejte funkci vypis **/

    //dopln

  return 0;
}

/* fce(typ * p ) { */
/*     p->slozka = ... */
/* } */

/* typ p; */
/* fce(&p); */

/* p*p = malloc(sizeof(typ p)) */
/*     fce(p) */
