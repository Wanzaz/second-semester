/* Encyklopedie jazyka C
 *
 * Modul s pomocnými podprogramy a makry.
 *
 * Tento hlavičkový soubor obsahuje makra a hlavičky pomocných podprogramů.
 * Jejich implementace se nachází ve zdrojovém souboru modulu.
 *
 * Tento hlavičkový soubor je potřeba do zdrojového textu vložit vždy jako
 * první, ještě před vložením systémových hlavičkových souborů.
 *
 * Copyright (c) David Martinek, 2021
 */

// Toto zabraňuje vícenásobnému vložení hlavičkového souboru do zdrojového textu.
#ifndef _POMOCNY_MODUL_H_
#define _POMOCNY_MODUL_H_

#include <stdbool.h>

// Tohle kouzlo je podmíněný překlad a makro, které vyčistí konzoli v linuxu a ve Windows.
#ifdef __unix__
  // příkaz pro unixovou konzoli, možná funguje i pod MacOS
  #define vycistiKonzoli() system("clear")
#else
  // příkaz pro konzoli ve Windows a DOSu
  #define vycistiKonzoli() system("cls")

  // Tohle zaříkání je nutné použít v překladači MINGW ve Windows, protože překladač běžně používá céčkovou knihovnu od MS,
  // která nemá správně implementováno rozšíření C99 a novější. Tento přepínač donutí překladač používat knihovnu šířenou
  // s MINGW. Bez tohoto woodoo ve Windows nefungují například některé formátovací značky příkazu printf (%zd, %zu, %hhd,
  // %lld aj.).
  // Aby tohle kouzlo zafungovalo, je potřeba tento define mít ve zdrojovém textu před systémovými #include.
  // Také je dobré si sundat ponožku, ukázat bosou nohou do čtyř světových stran a přát si brzký a potupný zánik firmy MS.
  #define __USE_MINGW_ANSI_STDIO 1
#endif // __unix__


/** Podprogram ze standardního vstupu přečte všechny znaky až do konce řádku.
 * Vyčistí tak vstup pro zadávání další hodnoty.
 *
 * Dá se také použít pro čekání, až uživatel stiskne Enter.
 */
void pozerKonecRadku(void);

/** Vrátí první nebílý znak zapsaný na řádku.
 * Pak požere všechny ostatní znaky až do konce řádku.
 */
int prvniPismenoNaRadku();

/** Pokud uživatel odpoví Q, vrací true. */
bool navratDoMenu();

/** Počká na stisk klávesy Enter na konci kapitoly. */
void konecKapitoly();


/**
 * Funguje jako printf, ale převede formátovací řetězec do CP852.
 */
int _printg(const char * format, ...);

// Poznámka: předpokládám, že na unixu je nastavena lokalizace cs_CZ.UTF-8
// a ve Windows konzole používá CP852.
#ifdef __unix__
  /**
   * Funguje v unixu jako printf, ale ve Windows převede formátovací řetězec do CP852.
   */
  #define printg(...) printf(__VA_ARGS__)
#else
  /**
   * Funguje v unixu jako printf, ale ve Windows převede formátovací řetězec do CP852.
   */
  #define printg(...) _printg(__VA_ARGS__)
#endif // __unix__


#endif // _POMOCNY_MODUL_H_
