/*
 * Projekt: Parametry odkazem
 * Popis: Umění předávání a zpracovávání parametrů a argumentů v rozličných funkcích s rozličnými typy.
 * Autor: David Martinek
 * Datum: 10. 2. 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

///////////////////////////////////////////////////////////////////////////////
// Příklad č. 1
// Funkce s parametry předávanými hodnotou.
// - Všimni si, že hodnoty parametrů a, b se uvnitř funkce mění.
// - Navenek se ale tato změna neprojeví.
// - Při volání se hodnoty argumentů zkopírují do parametrů (vnitřních
//   proměnných) a, b. Uvnitř funkce se pracuje s kopiemi původních hodnot.
// - Díky tomu lze při volání použít jako argumenty jak proměnné, tak konstanty.
int nsd(int a, int b)
{
  int c;
  while (b != 0)
  {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

void priklad01(void)
{
  printf("****************************************\n");
  printf("Priklad 01: Parametry predavane hodnotou\n");

  int cislo = 256;
  int vysledek = nsd(130, cislo);
// Všimni si, že argumentem může být proměnná i kostanta.
// Hodnota argumentu cislo se po zavolání funkce nezměnila.

  printf("int cislo = 256;\n");
  printf("int vysledek = nsd(130, cislo);\n");
  printf("vysledek => %d\n", vysledek);
  printf("cislo => %d\n", cislo);

  printf("****************************************\n");
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Příklad č. 2
// Funkce s parametry předávanými odkazem.
// - Při volání se jako argumenty musí dosadit adresy proměnných, typicky
//   referenčním operátorem & (vrací adresu proměnné).
// - Uvnitř se s původními hodnotami pracuje přes dereferenční operátor *, který
//   zpřístupňuje hodnotu, na kterou ukazuje adresa (tj. proměnná typu ukazatel).
// - Toto se používá, když chci vracet výsledky funkce přes parametry, ne
//   pomocí příkazu return jako návratovou hodnotu.
void vymena(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void priklad02(void)
{
  printf("***************************************\n");
  printf("Priklad 02: Parametry predavane odkazem\n");

  int m = 256;
  int n = 123;
  vymena(&m, &n);
// Všimni si, že argumentem teď NEMŮŽE být kostanta, musí jít o adresu proměnné.
// Proměnné m a n se teď změnily.

  printf(
    "int m = 256;\n"
    "int n = 123;\n"
    "vymena(&m, &n);\n"
  );
  printf("m => %d\n", m);
  printf("n => %d\n", n);

  int * u = &m;
  vymena(u, &n);
// Proměnná u je teď typu ukazatel - můžu do ní uložit adresu proměnné m.
// Při volání funkce vymena už nepoužívám &u, ale jenom u, protože tam chci
// předat adresu proměnné m (jejíž adresa je v u), nikoli adresu proměnné u!

  printf(
    "\n"
    "int * u = &m;\n"
    "vymena(u, &n);\n"
  );
  printf("m => %d\n", m);
  printf("n => %d\n", n);
  printf("u => %p\n", (void*)u);
  printf("*u => %d\n", *u);

// Tohle je použití neinicializovaných proměnných typu ukazatel.
// Tohle není syntaktická chyba (ale překladač hlásí varování), ale skončí to
// pravděpodobně havárií programu.
//  int * p;
//  int * q;
//  vymena(p, q);

  printf("***************************************\n");
}
///////////////////////////////////////////////////////////////////////////////

typedef struct _prvek Tprvek;

struct _prvek
{
  int delka;
  char pole[21]; // pole znaků může obsahovat textový řetězec
  int has;
};


///////////////////////////////////////////////////////////////////////////////
// Příklad č. 3
// Struktura předávaná hodnodou a odkazem.
// - Při volání platí stejná pravidla, jako u dvou předchozích ukázek.
// - Uvnitř se ke složkám parametru předaného hodnotou dostanu pomocí tečkového
//   operátoru (promenna.slozka).
// - Uvnitř se ke složkám parametru předaného odkazem dostanu pomocí šipkového
//   operátoru (promenna->slozka).
void struktury(Tprvek a, Tprvek *b)
{
  // kopie struktury
  // - tady s proměnnou b zacházím jako v předchozích ukázkách
  // - všimni si, že struktury jde kopírovat, i když obsahují pole
  *b = a;

  // Ukázka práce se složkami struktury a. Změny v této proměnné se navenek
  // funkce nijak neprojeví.
  a.delka = 123;
  a.has = 876;

  b->delka = 20;
  for (int i = 0; i < 21; ++i)
  {
    if (b->pole[i] == '\0')
    {
      b->delka = i;
      break;
    }
  }
  b->pole[b->delka] = '\0';

  b->has = 0;
  for (int i = 0; i < b->delka; ++i)
  {
    b->has += b->pole[i];
  }

  b->has %= b->delka;
}

void priklad03(void)
{
  printf("**************************************************\n");
  printf("Priklad 03: Struktury predavane hodnotou a odkazem\n");

  Tprvek x = { .pole = "Kokodak!" };
  Tprvek y;
  struktury(x, &y);

  printf(
    "Tprvek x = { .pole = \"Kokodak!\" };\n"
    "Tprvek y;\n"
    "struktury(x, &y);\n"
  );
  printf("x => { .delka = %d, .pole = %s, .has = %d }\n", x.delka, x.pole, x.has);
  printf("y => { .delka = %d, .pole = %s, .has = %d }\n", y.delka, y.pole, y.has);

// Tohle je použití neinicializované proměnné typu ukazatel.
// Tohle není syntaktická chyba (ale překladač hlásí varování), ale skončí to
// havárií programu.
//  Tprvek * u;
//  struktury(a, u);

  printf("***************************************\n");
}
///////////////////////////////////////////////////////////////////////////////



//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  priklad01();
  priklad02();
  priklad03();
  return 0;
}
