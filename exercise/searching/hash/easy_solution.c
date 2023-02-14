#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******** struktura osoba *******/
typedef struct
{
    char jmeno[21];
    int vek;
    bool obsazeno; //obsazeno 0 = ne, 1 = ano, zmeneno na false a true

} Tosoba;



/******** Vypis cele tabulky *******/
void vypis (Tosoba p[],int n)
{

    /** Pohlidejte si, ze obsazeno je 1, 0 totiz znamena, ze polozka neexistuje, podle toho vypisujte,
      tzn. vypisujete pouze pole, kde obsazeno je 1. **/

    for (int i=0; i<n; i++)
    {
        if (p[i].obsazeno)
            printf("%s %d\n", p[i].jmeno, p[i].vek);
    }
    printf("\n");
}


/******** Inicializace *******/
void init(Tosoba p[],int n)
{
    /** v kazde bunce pole nastav obsazeno na 0:  pole[i].obsazeno=0;**/
    for (int i=0; i<n; i++)
        p[i].obsazeno = false;

}


/******** Hashovaci funkce *******/
int hashfunkce (int vek_vkladane_osoby, int delkapole)
{
    /** vrati bud upraveny vek (podle delky pole) nebo totalni cif soucet, nebo jednotky, nebo udelejte vlastni hashfunkci podle delky pole*/
    return vek_vkladane_osoby % delkapole;
}


/******** Vloz do tabulky *******/
void vlozHtab(Tosoba p[],int n, Tosoba nova)
{
    /** dopln (viz Classroom str. 35)**/
    int index = hashfunkce(nova.vek, n);
    p[index] = nova;
    p[index].obsazeno = true;

}

/******** Vymaz z tabulky *******/
void vymazHtab(Tosoba p[],int n, Tosoba mazana)
{
    int index = hashfunkce(mazana.vek, n);
    p[index].obsazeno = false;
}

/******** Najdi v tabulce *******/
Tosoba najdiHtab(Tosoba p[],int n, int vek)
{
    int index = hashfunkce(vek, n);
    return p[index];

}



/******** MAIN ******************************************************/
int main(void)
{
    /** 1. Vytvor osoba pole[10] + dalsi pomocne promenne, popr. pole jine delky pokud chcete**/

    // dopln
    Tosoba pole[11];

    /** 3. Zavolej inicializaci pole: funkci init (chceme vsechny pole nastavit na obsazeno = 0) **/

    // dopln
    init(pole, 11);

    /** 4. Do pole bude uzivatel zadavat osoby: jmeno a vek, a to tak dlouho, dokud uzivatel nezada nesmyslny vek, tj.
      napriklad zaporny. **/
    Tosoba nova;
    printf("Zadej jmeno: ");
    scanf("%20s", nova.jmeno);
    printf("Zadej vek: ");
    scanf("%d", &nova.vek);
    while(nova.vek > 0)
    {
        /**  zavolejte funkci vlozHtab a pridejte novou osobu**/
        vlozHtab(pole, 11, nova);
        printf("Zadej jmeno: ");
        scanf("%20s", nova.jmeno);
        printf("Zadej vek: ");
        scanf("%d", &nova.vek);
    }


    /** 3. Zavolejte funkci vypis **/

    vypis(pole, 11);


    /** 4. Zavolejte funkci pro vyhledani osoby ... vyhledavame podle veku **/

    printf("Zadej vek osoby, kterou hledame: ");
    int vek;
    scanf("%d", &vek);
    /**  zavolej funkci najdiHtab
      vypis jmeno osoby, pokud existuje (obsazeno == 1), jinak vypis, ze takova osoba neni**/
    Tosoba hledana = najdiHtab(pole, 11 , vek);
    if (hledana.obsazeno)
        printf("Hledana osoba: %s %d\n", hledana.jmeno, hledana.vek);
    else
        printf("Takova osoba se tu nevyskytuje.\n");


    /** 5. Zavolejte funkci pro odebrani nejake osoby ... odebirame osobu podle jejiho veku **/

    printf("Zadej vek osoby, kterou odebereme: ");
    scanf("%d", &vek);
    Tosoba mazana = najdiHtab(pole, 11 , vek);
    if (mazana.obsazeno)
    {
        vymazHtab(pole, 11, mazana);
        printf("Osoba %s %d byla smazana.\n", mazana.jmeno, vek);
    }
    else
        printf("Takova osoba se tu nevyskytuje.\n");
    //zavolej funkci vymazHtab

    /** 6. Zavolejte funkci vypis **/

    vypis(pole, 11);

    return 0;
}
