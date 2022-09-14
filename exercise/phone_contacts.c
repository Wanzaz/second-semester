/*
 * Project: Phone Contacts
 * Author: Andrew
 * Date: 14.9.2022
 */

//#define NDEBUG

/* #include "gvid.h"       // par drobnosti pro zjednoduseni prace */
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

/*
DESCRIPTION OF THE TASK:
1. Napište program, ve kterém zadáte počet celých čísel a napíšete funkci pro načtení těchto čísel do pole a další funkci pro výpis tohoto pole.
2. Do stejného programu udělejte to stejné, ale s textovými řetězci (například jména).
3. Vytvořte strukturu "kontakt", která bude obsahovat jméno a telefonní číslo (stačí 5 cifer). Definujte pole kontaktů. Vyplňte si ho daty (viz níže). Napište funkci, která toto pole struktur vypíše.
4. (Bonus) Napište funkci, která načte nový kontakt a vloží ho do pole.
*/

#define LENGTH 1000


typedef struct{
    char name[16];
    int phone_number;
} TContact;


/*void test(void)
{
    dprintf("Makej!\n");
}*/

void loadArray(int array[], int length, int *number) { // pointer to integer
    //*number = 10; // dereference operator
  
    printf("Enter the size of an array (max %d): ", LENGTH);
    // there doesn't have to be pointer or ampersand (&*number) because we already specified that
    scanf("%d", number);
}

void task1(void) {
    int array[LENGTH];
    int number;
    
    loadArray(array, LENGTH, &number);
}



void loadNumbers(int number, int array[])
{
      for(int index=0;index<number;index++) {
          array[index] = index + 1;
      }
      
      
}


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
    int array[LENGTH];
    TContact contacts[]={{"Pavel",12345},{"Jana",54555},{"Oskar",12332},{"Emil",55555},{"Jindra",87411},{"Petr", 98999}};
    
    
    /* test(); */
    return 0;
}





