/* Encyklopedie jazyka C
 *
 * Modul s pomocnými podprogramy a makry.
 *
 * Tento zdrojový soubor modulu obsahuje implementaci pomocných podprogramů.
 *
 * Copyright (c) David Martinek, 2021
 */

#include "pomocny-modul.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

void pozerKonecRadku(void)
{
  int c;
  // přeskočí vše do konce řádku
  while ( (c = getchar()) != '\n' && c != EOF)
  {} // prázdné tělo cyklu
}

int prvniPismenoNaRadku()
{
  int c;
  // přeskočí mezery
  while ( isblank(c = getchar()) )
  {} // prázdné tělo cyklu

  if (c != '\n')
    pozerKonecRadku(); // přečte a zahodí vše ostatní na řádku

  return c;

}

bool navratDoMenu()
{
  printg("### Návrat do menu? -> Q, Pokračovat? -> Enter: ");
  return tolower(prvniPismenoNaRadku()) == 'q';
}

void konecKapitoly()
{
  printg("\nPro návrat do menu stiskni Enter.\n");
  pozerKonecRadku(); // čeká, dokud uživatel nestiskne Enter.
}



// Tohle není obyčejný hlavičkový soubor. Je překódovaný do CP852. Neupravovat!
// Je v něm definice konstantní proměnné. Nesmí se proto vkládat do více modulů!
#include "utf8nacp852.h"
/**
 * Funguje jako printf, ale převede formátovací řetězec do CP852.
 *
 * Používá tabulku UTF8_NA_CP852 ze souboru "utf8nacp852.h".
 *
 */
int _printg(const char * format, ...)
{
  va_list args;
  va_start(args, format);

  char upravenyFormat[strlen(format)+1];

  int j = 0;
  for (int i = 0; format[i] != 0; ++i, ++j)
  {
    int z1 = format[i];
    if (z1 >= -61 && z1 <= -59)
    {
      z1 += 61;
      int z2 = format[++i]+128;
      upravenyFormat[j] = UTF8_NA_CP852[z1][z2];
    }
    else
      upravenyFormat[j] = z1;
  }
  upravenyFormat[j] = '\0';

  int result = vprintf(upravenyFormat, args);

  va_end(args);
  return result;
}

