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



void loadNumbers(int array[], int length, int *number);
void showNumbers(int array[], int length, int *number);
void task1(void);

void loadStrings(char array[][16], int current_name_amount);
void showStrings(char array[][16], int current_name_amount);
void task2(void);

void showStruct(TContact array[], int current_name_amount);
void task3(void);

void loadStruct(TContact array[], int current_name_amount);
void task4(void);

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
    int array[LENGTH];
    TContact contacts[]={{"Pavel",12345},{"Jana",54555},{"Oskar",12332},{"Emil",55555},{"Jindra",87411},{"Petr", 98999}};

	/* task1(); */
	/* task2(); */
	/* task3(); */
	task4();
    
    
    return 0;
}


/*void test(void)
{
    dprintf("Makej!\n");
}*/


/* -------------Task 1--------------- */

void loadNumbers(int array[], int length, int *number) { // pointer to integer
    //*number = 10; // dereference operator
	for (int index=0; index < *number; index++) {
		array[index] = index + 1;
	}
  
}

void showNumbers(int array[], int length, int *number) {
	for (int index=0; index < *number; index++) {
		printf("%d\n", index);
	}
	
}

void task1(void) {
    int array[LENGTH];
    int number;
    printf("Enter the size of an array (max %d): ", LENGTH);
    // there doesn't have to be pointer or ampersand (&*number) because we already specified that
    scanf("%d", &number);
	number += 1;
    
    loadNumbers(array, LENGTH, &number);
	showNumbers(array, LENGTH, &number);
}


/* -------------Task 2--------------- */

void loadStrings(char array[][16], int current_name_amount) { 
	int index;
	for (index=0; index < current_name_amount; index++) {
		printf("Enter the %d. name: ", index + 1);
		scanf("%s", array[index]);
	}
		/* array[*current_size][index] = '\0'; */
  
}

void showStrings(char array[][16], int current_name_amount) {
	int index;
	for (index=0; index < current_name_amount; index++) {
		printf("%s\n", array[index]);
	}
	/* for (index=0; array[index][16] != '\0'; index++) { */
	/* 	printf("%s", array[index]); */
	/* } */
	
}

void task2(void) {
	int name_amount;
	char array[LENGTH][16];
    printf("Enter a amount of names (max %d): ", LENGTH);
    scanf("%d", &name_amount);
	loadStrings(array, name_amount);
	showStrings(array, name_amount);

}


/* -------------Task 3--------------- */

void showStruct(TContact array[], int current_name_amount) {
	int index;
	for (index=0; index < current_name_amount; index++) {
		printf("Name: %s, Phone: %d\n", array[index].name, array[index].phone_number);
	}
}

void task3(void) {
	int name_amount=6;
    TContact contacts[]={{"Pavel",12345},{"Jana",54555},{"Oskar",12332},{"Emil",55555},{"Jindra",87411},{"Petr", 98999}};

	showStruct(contacts, name_amount);
}


/* -------------Task 4--------------- */

void loadStruct(TContact array[], int current_name_amount) {
	int index;
	for (index=0; index < current_name_amount; index++) {
		printf("Enter the %d. name: ", index + 1);
		scanf("%15s", array[index].name);
		printf("Enter the %d. phone: ", index + 1);
		scanf("%d", &array[index].phone_number);
		printf("\n");
	}
}

void task4(void) {
	int contact_amount;
    printf("Enter a amount of contacts (max %d): ", LENGTH);
    scanf("%d", &contact_amount);

    TContact new_contacts[LENGTH]={};
	loadStruct(new_contacts, contact_amount);
	showStruct(new_contacts, contact_amount);
}


