/* Encyklopedie jazyka C
 *
 * Kapitola 6 - Funkce
 *
 * Copyright (c) David Martinek, 2021-2022
 */
#define VERZE "2.1"

// Mimo jiné obsahuje funkci printg, která nahrazuje printf, aby šlo tisknout
// text s českou diakritkou i v konzoli Windows, ačkoli je tento zdrojový
// text v kódování UTF-8.
#include "pomocny-modul.h"

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <stdbool.h>
#include <ctype.h>
// #include <math.h>
// #include <float.h>
// #include <limits.h>

// Tady jsou jen hlavičky funkcí. Implementace je za funkcí main.
void podprogram(void);
void hlavicka(void);
void procedura(void);
void funkce(void);
void prototypyAModuly(void);

void parametryHodnotou(void);
void parametryOdkazem(void);

void odkazemUvnitrFunkce(void);
void rekurze(void);


int main(void)
{
  int volba = 'Q';
  while (1)
  {
    if (volba != 'Q')
    {
      vycistiKonzoli();
    }

    printg(
      "==============================================================\n"
      "Encyklopedie jazyka C - Funkce (verze %s)\n"
      "(c) David Martinek, 2021\n"
      "Zároveň s programem sleduj i zdrojový text!\n"
      "==============================================================\n"
      "\n"
      , VERZE
    );

    printg(
      "Podprogramy\n"
      "  A - Podprogram - co to je\n"
      "  B - Hlavička - rozhraní podprogramu\n"
      "  C - Procedura - jednoduchý podprogram (příkaz)\n"
      "  D - Funkce - podprogram s výsledkem (výraz)\n"
      "  E - Prototypy a moduly\n"
      "\n"
      "Podprogramy s parametry\n"
      "  F - Parametr předávaný hodnotou (kopií)\n"
      "  G - Parametr předávaný odkazem (na originální proměnnou)\n"
      "\n"
      "Důležité detaily\n"
      "  H - Předávání odkazem uvnitř podprogramu\n"
      "  I - Rekurze\n"
//      "  J - \n"
//      "  K - \n"
//      "  L - \n"
      "\n"
      "Q nebo Enter - Konec\n"
      "\n"
      "Zadej písmeno volby: "
    );
    volba = toupper(prvniPismenoNaRadku());
    vycistiKonzoli();

    switch (volba)
    {
    case 'A':
      podprogram();
      break;
    case 'B':
      hlavicka();
      break;
    case 'C':
      procedura();
      break;
    case 'D':
      funkce();
      break;
    case 'E':
      prototypyAModuly();
      break;
    case 'F':
      parametryHodnotou();
      break;
    case 'G':
      parametryOdkazem();
      break;
    case 'H':
      odkazemUvnitrFunkce();
      break;
    case 'I':
      rekurze();
      break;
//    case 'J':
//      break;
//    case 'K':
//      break;

    case EOF: // Kdyby to někdo ukončil pomocí Ctrl+Z (nebo Ctrl+D v Linuxu)
    case 'Q':
    case '\n':
      printg("Končím program.\n");
      return 0; // return v main ukončí program

    default:
      printg("Neznámá volba. Zkus to znovu.\n");
      break;
    }

  }

  return 0;
}



///////////////////////////////////////////////////////////////////////////

void podprogram(void)
{
  printg(
    "***************************\n"
    "** Podprogram - co to je **\n"
    "\n"
    "- Relativně samostatný kus kódu, který má své jméno a přesně definované\n"
    "  rozhraní, kterým komunikuje se zbytkem programu.\n"
    "- Zjednodušuje práci\n"
    "  - Jde ho použít opakovaně.\n"
    "  - Umožňuje se soustředit na malou část celkového problému.\n"
    "  - Princip stavebnice: z malých podprogramů jde snadněji složit velký program.\n"
    "\n"
    "Tip: Nauč se psát jednoduché podprogramy dříve než cokoli jiného.\n"
    "\n"
    "Rozhraní\n"
    "- Popsáno pomocí hlavičky\n"
    "- Parametry: popisují místa, kterými proudí data dovnitř podprogramu.\n"
    "- Návratová hodnota (u funkcí): výsledek, který lze získat v místě zavolání.\n"
    "  Návratová hodnota = funkční hodnota\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Druhy podprogramů\n"
    "- Procedura\n"
    "  - Uživatelský příkaz\n"
    "  - Nemá návratovou hodnotu.\n"
    "  - Slouží k provedení nějaké akce.\n"
    "\n"
    "- Funkce\n"
    "  - Uživatelský výraz\n"
    "  - Primárně slouží k výpočtům, které mají výslednou hodnotu.\n"
    "  - Vrací výslednou hodnotu, kterou lze dále použít v místě volání.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Dvě fáze práce s podprogramem\n"
    "- Vytváření\n"
    "  - Naplánování rozhraní - hlavička\n"
    "  - Zápis kódu - tělo\n"
    "\n"
    "- Používání\n"
    "  - Volání podprogramu\n"
    "  - Předání argumentů (hodnot) správných typů ve správném pořadí\n"
    "  - Zpracování výsledné hodnoty (u funkcí)\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Vedlejší efekty\n"
    "- Chování podprogramu, kdy data do/z podprogramu proudí mimo rozhraní\n"
    "  definované v hlavičce.\n"
    "- Obecně zpomalují program a mohou být příčinou chyb!\n"
    "\n"
    "- Záměrné vedlejší efekty (většninou chtěné)\n"
    "  - Komunikace s uživatelem\n"
    "  - Tisk na konzoli\n"
    "  - Práce se soubory\n"
    "\n"
    "- Nevhodné vedlejší efekty\n"
    "  - Vznikají omylem nebo z neznalosti.\n"
    "  - Způsobují zákeřné, obtížně odhalitelné chyby!\n"
    "  - Používání globálních proměnných.\n"
    "  - Vytváření zbytečných parametrů místo lokálních proměnných.\n"
    "  - Klonování kódu místo tvorby obecných podprogramů.\n"
    "\n"
    /*
    Typický příklad: Rozkopíruji jeden cyklus 10krát, místo abych 10krát
    zavolal podprogram s jedním cyklem. Často se pak mezi takto klonovanými
    kousky kódu přenášejí data v lokálních proměnných, která by se přenášet
    neměla - v podprogramu by takové proměnné bezpečně zanikly a při dalším
    zavolání by se znovu vytvořily, což je mnohem bezpečnější (a taky
    pohodlnější).
    */
  );

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}


///////////////////////////////////////////////////////////////////////////

/** Vytiskne prvních n násobků zadaného čísla. */
void tiskniNNasobku(int n, double cislo)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%.2f ", cislo*(i+1));
  }
  printf("\n");
}

/** Vrátí součet prvních n násobků zadaného čísla jako funkční hodnotu. */
double soucetNNasobku(int n, double cislo)
{
  double vysledek = 0;
  for (int i = 0; i < n; ++i)
  {
    vysledek += cislo*(i+1);
  }
  return vysledek;
}

void hlavicka(void)
{
  printg(
    "*************************************\n"
    "** Hlavička - rozhraní podprogramu **\n"
    "\n"
    "- Hlavička představuje popis rozhraní - míst, kudy data putují do\n"
    "  podprogramu a kudy se posílají výsledná data zpět.\n"
    "- Hlavička popisuje, jak se má podprogram volat.\n"
    "\n"
    "Syntaxe\n"
    "  <návratový typ> <název podprogramu>(<seznam parametrů>)\n"
    "\n"
    "  - <návratový typ> - void u procedur nebo konkrétní typ u funkcí\n"
    "  - <název podprogramu> - identifikátor podprogramu\n"
    "  - <seznam parametrů> - seznam deklarací proměnných oddělených středníky\n"
    "  - Končí-li hlavička středníkem, jde o prototyp (viz další kapitoly).\n"
    "    Pokud středník chybí musí následovat tělo a jde tedy o implementaci\n"
    "    podprogramu.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Vstupní body podprogramu - parametry deklarované v hlavičce\n"
    "- Každý parametr je místo, kterým se při volání zadávají vstupní data.\n"
    "- Při volání musí pořadí a typy argumentů odpovídat pořadí a typům parametrů.\n"
    "- Jméno parametru je viditelné jen uvnitř podprogramu, nikoli mimo něj!\n"
    "\n"
    "Pozor! Častá chyba\n"
    "- Seznam parametrů neslouží k deklaraci pomocných proměnných!\n"
    "- Pomocné proměnné vyrábějte jako lokální uvnitř těla podprogramu.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Výstupní bod podprogramu\n"
    "- Funkce produkují výsledek - funkční hodnotu. Jeho typ je specifikován\n"
    "  návratovým typem.\n"
    "- Funkce vracejí výsledek pomocí příkazu return.\n"
    "- Další výstupní body, kudy jde data dostat ven z podprogramu, jsou\n"
    "  speciálně vytvořené parametry - tzv. parametry předávané odkazem.\n"
    "- Parametry předávané odkazem umožňují předávat data ven i procedurám.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Příklad: deklarace procedury a funkce (implementace jsou jinde)\n"
    "  void tiskniNNasobku(int n, double cislo);\n"
    "  double soucetNNasobku(int n, double cislo);\n"
    "\n"
    "Příklad: volání procedury a funkce\n"
    "- Při volání se musí dosadit všechny argumenty na místa parametrů.\n"
    "- Argumenty musí být ve správném pořadí.\n"
    "  tiskniNNasobku(5, 4.5);\n"
    "  => "
  );
  tiskniNNasobku(5, 4.5);

  double vysledek = soucetNNasobku(5, 4.5);

  printg(
    "\n"
    "Výsledek funkce se používá v jiném výrazu - nejčastěji v přiřazovacím.\n"
    "  double vysledek = soucetNNasobku(5, 4.5);\n"
    "  => vysledek: %g\n"
    "\n"
    , vysledek
  );

  /*Terminologická poznámka: parametr vs. argument

    Parametr (nebo také formální parametr) je zástupná proměnná deklarovaná
    v hlavičce podprogramu. Kód podprogramu pracuje s hodnotou, která je mu
    zadána při volání přes tuto proměnnou. Podprogram nevidí kód mimo své tělo,
    nevidí ani proměnné (resp. jejich názvy) deklarované v jiném podprogramu
    (například ve funkci main), proto může být název parametru jakýkoli, klidně
    i shodný s proměnnou vyrobenou mimo podprogram. Obvykle však volíme takový
    název, aby v kontextu daného podprogramu byl co nejvýstižnější.

    Podprogram může mít i více paramertů. Důležité jsou jejich typy a pořadí
    zadané v hlavičce.


    Argument (nebo také skutečný parametr) je výraz, jehož hodnota se předává
    podprogramu při volání a jehož hodnota je následně zkopírována do parametru
    volaného podprogramu. Typ předávaného argumentu musí být shodný nebo
    kompatibilní s typem odpovídajícího parametru v hlavičce. Má-li podprogram
    více parametrů, musí se při volání zadat přesně stejný počet argumentů
    a musí sedět jejich typy a pořadí.

    Častou začátečnickou chybou je při volání podprogramu prostě opsat hlavičku
    i s deklaracemi parametrů. To je pochopitelně nesmysl, protože v místech,
    kde překladač očekává argumenty najednou najde deklarace proměnných, se
    které mu nedávají žádný smysl.
  */
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Ukázka jednoduché procedury s číselným parametrem.
 *
 * Vytiskne n-krát znak hvězdičky, kde číslo n je zadáno jako argument při
 * volání.
 *
 * \param n int Parametr, v němž se při zavolání ocitne kopie hodnoty argumentu.
 * \return void Návratový typ je void, proto jde o podprogram, který
 *              je příkazem - je to procedura.
 *
 */
void hvezduNKrat(int n)       // Toto je hlavička.
{
  // Složené závorky ohraničují tělo.
  for (int i = 0; i < n; ++i)
  {
    printf("*");
  }
  printf("\n");
}

void procedura(void)
{
  printg(
    "************************************************\n"
    "** Procedura - jednoduchý podprogram (příkaz) **\n"
    "\n"
    "- Procedura je uživatelsky vyrobený, znovupoužitelný příkaz.\n"
    "\n"
    "Syntaxe\n"
    "  void <jméno procedury>(<seznam parametrů>)\n"
    "  {\n"
    "    <posloupnost příkazů>\n"
    "  }\n"
    "\n"
    "- Procedura má v hlavičce prázdný návratový typ (void).\n"
    /*
    Čistě formálně jazyk C pojem procedura nezná. Jazyk C zná jenom pojem funkce.
    To, co je zde popisováno je formálně funkce s prázdným návratovým typem.
    Je ale užitečné o takovém podprogramu mluvit a psát jako o proceduře kvůli
    výstižnosti. Mezi oběma typy podprogramů, tj. procedurami a funkcemi, jsou
    totiž rozdíly jak v implementační části, tak i při jejich volání.
    Některé jiné jazyky (např. Pascal) tyto pojmy rozlišují už na úrovni jazyka
    pomocí rozdílných klíčových slov.
    */
    "- Hlavička představuje popis rozhraní (viz kapitola Prototypy a moduly).\n"
    "- Tělo obsahuje kód podprogramu.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Příkaz return\n"
    "  return;\n"
    "\n"
    "- Okamžitě ukončí vykonávání procedury a vrací řízení do místa volání.\n"
    "- Může se v těle procedury vyskytnout libovolněkrát.\n"
    "- V proceduře nemá žádný parametr.\n"
    "- V proceduře není povinné jej použít, skončí sama po posledním příkazu.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Ukázka procedury\n"
    "  void hvezduNKrat(int n)       // Toto je hlavička.\n"
    "  {                             // Složené závorky ohraničují tělo.\n"
    "    for (int i = 0; i < n; ++i)\n"
    "    {\n"
    "      printf(\"*\");\n"
    "    }\n"
    "    printf(\"\\n\");\n"
    "  }\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Volání procedury\n"
    "- Používá se jako příkaz. Nejde použít ve výrazech.\n"
    "- Zápis volání procedury vždy končí středníkem (;).\n"
    "- Volá se jménem. Následují kulaté závorky do nichž se dosadí seznam\n"
    "  argumentů, tj. hodnot, jejichž typy a pořadí musí odpovídat hlavičce.\n"
    "- Kulaté závorky nejde při volání vynechat ani u procedur bez parametrů.\n"
    "\n"
    "Ukázka volání procedury\n"
    "  hvezduNKrat(5);\n"
    "  => "
  );
  hvezduNKrat(5);

  /*Kulaté závorky nejde vynechat, protože jde o operátor volání podprogramu.
    Název podprogramu bez kulatých závorek je ukazatel na podprogram - viz
    kapitola o ukazatelích.
   */

  printg(
    "  hvezduNKrat(10);\n"
    "  => "
  );
  hvezduNKrat(10);

  printf(
    "\n"
  );

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Chybné použití\n"
    "  hvezduNKrat();\n"
    "  - Chyba při překladu - too few arguments - málo argumentů\n"
    "  - Musí se dosadit tolik argumentů, kolik je v hlavičce parametrů.\n"
    "  - Procedura hvezduNKrat má jeden parametr, proto se očekává jeden argument.\n"
    "\n"
    "  hvezduNKrat(int n);\n"
    "  - Chyba při překladu - expected expression before \'int\'.\n"
    "  - Opsat hlavičku při volání je syntaktická chyba.\n"
    "  - V kulatých závorkách se očekává smysluplný výraz, ne deklarace.\n"
    "  - Očekává výraz před slovem int, protože překladač slovu int\n"
    "    v tomto místě nerozumí - je to pro něj nesmysl.\n"
    "\n"
  );

  //  hvezduNKrat();      // chyba při překladu - nedosazen žádný argument
  //  hvezduNKrat(int n); // syntaktická chyba - jako argument očekává smysluplný výraz, ne deklaraci
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Demonstrační funkce pro součet dvou argumentů.
 *
 * \param a float První sčítanec.
 * \param b float Druhý sčítanec.
 * \return float Funkce vrací jako výsledek součet svých parametrů.
 */
float secti(float a, float b)
{
  return a + b;
}

void funkce(void)
{
  printg(
    "*********************************************\n"
    "** Funkce - podprogram s výsledkem (výraz) **\n"
    "\n"
    "- Funkce je uživatelsky vyrobený, znovupoužitelný, pojmenovaný výraz.\n"
    "\n"
    "Syntaxe\n"
    "  <návratový typ> <jméno funkce>(<seznam parametrů>)\n"
    "  {\n"
    "    <posloupnost příkazů>\n"
    "    return <výsledek>;\n"
    "  }\n"
    "\n"
    "- Funkce má v hlavičce konkrétní návratový typ (tedy ne void).\n"
    "- Hlavička představuje popis rozhraní (viz kapitola Hlavička).\n"
    "- Tělo obsahuje kód podprogramu.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Příkaz return\n"
    "  return <výsledek>;\n"
    "\n"
    "- Okamžitě ukončí vykonávání funkce a vrací řízení do místa volání,\n"
    "  přičemž vrací výslednou hodnotu funkce.\n"
    "- Za klíčové slovo return se píše výraz obsahující výslednou (návratovou)\n"
    "  hodnotu funkce, který musí být typově kompatibilní s návratovým typem.\n"
    "- Musí být povinně na konci těla, ale je možné jej použít i na více místech.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Ukázka funkce\n"
    "  float secti(float a, float b)\n"
    "  {\n"
    "    return a + b;\n"
    "  }\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Volání funkce\n"
    "- Funkce má výsledek který jde použít jako součást většího výrazu\n"
    "  (nejčastěji přiřazovacího).\n"
    "- Pokud je funkce zavolána jako příkaz, výsledek se ignoruje.\n"
    "\n"
    "  float soucet = secti(1.2, 3.8) * secti(-0.5, 5.5);\n"
  );
  float soucet = secti(1.2, 3.8) * secti(-0.5, 5.5);

  printg(
    "  => soucet: %.1f\n"
    "\n"
    , soucet
  );

  /* Poznámka - rozdíly mezi funkcí a procedurou

  Někdy je užitečné vytvářet funkce, jejichž primárním účelem není návrat
  výsledné hodnoty, ale nějaká činnost, pro níž by bylo logické použít
  proceduru. Návratová hodnota je u takových funkcí jakýsi užitečný "bonus"
  navíc.

  Často se tímto způsobem vrací chybové kódy. Často to dělají funkce ze
  standardní knihovny jazyka C, jako například printg, scanf aj. Je pak na
  uživateli těchto funkcí, zda navrácenou hodnotu použije nebo ne. Například
  u funkce printg tuto hodnotu potřebujeme málokdy, proto tuto funkci používáme
  spíše jako proceduru a výsledná hodnota se pak jednoduše ignoruje. U funkce
  scanf je tato hodnota velmi důležitá, proto bychom ji měli vždy získat
  a zkontrolovat. V opačném případě hrozí havárie programu. Před použitím
  každého podprogramu je důležité znát jeho chování a přečíst si jeho
  dokumentaci.
  */

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

void prototypyAModuly(void)
{
  printg(
    "***********************\n"
    "** Prototyp a moduly **\n"
    "\n"
    "Prototyp\n"
    "- Prototyp podprogramu (procedury nebo funkce) je samostatně zapsaná\n"
    "  hlavička ukončená středníkem.\n"
    "- Prototyp vždy předchází implementaci podprogramu (hlavička + tělo).\n"
    "- Dobrým zvykem je psát prototypy na začátek programu (před funkci main)\n"
    "  a implementace na konec (za funkci main).\n"
    "\n"
    "Moduly\n"
    "- Prototypy není povinné používat, ale je to užitečné - např. s ohledem\n"
    "  na přehlednost a také pozdější tvorbu modulů a knihoven.\n"
    "- Při tvorbě modulů se prototypy zapisují do hlavičkových souborů (.h)\n"
    "  a implementace do zdrojových souborů (.c).\n"
    "- Díky tomuto rozdělení lze vytvářet veřejné a privátní podprogramy.\n"
    "- Veřejné mají prototyp uveden v hlavičkovém souboru, privátní ne.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Ukázka triviálního programu s modulem\n"
    "soubor modul.h\n"
    "  /** Vytiskne n-krát hvězdičku. */\n"
    "  void hvezduNKrat(int n); // tady je pouze prototyp\n"
    "\n"
    "soubor modul.c\n"
    "  #include \"modul.h\"    // natáhne rozhraní modulu\n"
    "  #include <stdio.h>    // natáhne rozhraní systémové knihovny\n"
    "  void hvezduNKrat(int n) // tady už je implementace\n"
    "  {\n"
    "    for (int i = 0; i < n; ++i)\n"
    "    {\n"
    "      printf(\"*\");\n"
    "    }\n"
    "    printf(\"\\n\");\n"
    "  }\n"
    "\n"
    "soubor program.c\n"
    "  #include \"modul.h\"    // natáhne rozhraní modulu\n"
    "  int main(void)\n"
    "  {\n"
    "    hvezduNKrat(10);  // volání podprogramu z modulu\n"
    "    return 0;\n"
    "  }\n"
    "\n"
  );


  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Ukázková procedura se dvěma parametry předávanými hodnotou (kopií).
 *
 * Parametry a, b jsou zde měněny, ale tato změna se v místě volání neprojeví,
 * protože se zde pracuje s kopií argumentů. Parametry a, b zaniknou na konci
 * těla, tudíž se jakékoli změny v nich ztratí.
 *
 * \param a float Parametr předávaný hodnotou.
 * \param b float Parametr předávaný hodnotou.
 */
void jalovaZamena(float a, float b)
{
  float c = a;
  a = b;          // V parametrech a, b jsou jen kopie argumentů.
  b = c;
}

void parametryHodnotou(void)
{
  printg(
    "*****************************************\n"
    "** Parametr předávaný hodnotou (kopií) **\n"
    "\n"
    "- Standardní způsob práce s parametry podprogramu.\n"
    "- Slouží pro předávání dat do podprogramu.\n"
    "- Při volání jde jako argument předat libovolný výraz, který je typově\n"
    "  kompatibilní s odpovídajícím parametrem deklarovaným v hlavičce.\n"
    "- Hodnota argumentu se při volání kopíruje do dočasné proměnné - parametru.\n"
    "- Podprogram pracuje s kopií hodnoty argumentu => změna hodnoty parametru\n"
    "  uvnitř podprogramu nemá vliv na původní argument.\n"
    "- Parametr je pomocná proměnná, která se při zavolání podprogramu vytvoří\n"
    "  v části paměti zvané zásobník. => Parametr po skončení podprogramu zaniká.\n"
    "- Původní argument se nemění. => Může jím být i konstanta nebo výraz\n"
    "- Jméno parametru je viditelné jen uvnitř podprogramu, ne mimo něj.\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Příklad\n"
    "- Procedura mění své parametry, ale tato změna se ven nedostane.\n"
    "\n"
    "  void jalovaZamena(float a, float b)\n"
    "  {\n"
    "    float c = a; \n"
    "    a = b;          // V parametrech a, b jsou jen kopie argumentů.\n"
    "    b = c;\n"
    "  }\n"
  );

  jalovaZamena(3.1, 4.0+0.5); // Tohle jde, ale zde to nemá smysl.
  float m = 3.1, n = 4.5;
  jalovaZamena(m, n);         // Tohle s argumenty taky nic neudělá.

  printg(
    "\n"
    "Volání s předáváním hodnotou\n"
    "\n"
    "  jalovaZamena(3.1, 4.0+0.5); // Tohle jde, ale zde to nemá smysl.\n"
    "  float m = 3.1, n = 4.5;\n"
    "  jalovaZamena(m, n);         // Tohle s argumenty taky nic neudělá.\n"
    "  => m: %g, n: %g           // Mají pořád původní hodnoty. \n"
    "\n"
    , m, n
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Ukázková procedura se dvěma parametry předávanými odkazem.
 *
 * Tato procedura provádí záměnu hodnot proměnných předaných při volání odkazem.
 *
 * V této proceduře se nepracuje přímo s proměnnými a, b, ale s hodnotami, na
 * které odkazují. Proto je potřeba v těle pracovat s výrazy *a, *b.
 *
 * Samotné parametry a, b vlastně jsou ukazatele předávané hodnotou. Kdybychom
 * měnili samotné parametry a, b, měnili bychom ukazatele, nikoli proměnné, na
 * které odkazují. Pokud bychom pak pracovali s hodnotami *a, *b už by zřejmě
 * šlo o odkazy na jiná místa v paměti než bylo původně zamýšleno a způsobilo
 * by to chybu programu nebo dokonce havárii. Při předávání odkazem je potřeba
 * vědět, co děláte!
 *
 * \param a float* Parametr předávaný odkazem - ukazatel na původní proměnnou.
 * \param b float* Parametr předávaný odkazem - ukazatel na původní proměnnou.
 */
void zamena(float *a, float *b)
{
  float c = *a; // Místo a používáme *a, místo b pak *b.
  *a = *b;      // a obsahuje adresu původní proměnné, *a je původní proměnná
  *b = c;
}

void parametryOdkazem(void)
{
  printg(
    "**********************************************************\n"
    "** Parametr předávaný odkazem (na originální proměnnou) **\n"
    "\n"
    "- Speciální způsob práce s parametry podprogramu.\n"
    "- Slouží pro předávání dat dovnitř, ale i ven z podprogramu.\n"
    "- V jazyce C jsou řešeny takto\n"
    "  - Parametr se deklaruje jako typ ukazatel.\n"
    "  - Uvnitř podprogramu se s ním pracuje přes dereferenční operátor (*).\n"
    "  - Při volání se jako argument zadává ukazatel na proměnnou - typicky\n"
    "    pomocí referenčního operátoru (&)\n"
    "  - Původní proměnná leží mimo oblast paměti vyhrazenou pro daný\n"
    "    podprogram. => Původní proměnná přežije i konec podprogramu.\n"
    "\n"
    "Pozor!\n"
    "- Jako argument nejde zadávat výrazy (R-hodnoty) ani konstanty.\n"
    "- Argumentem musí být ukazatel na existující paměťovou buňku (proměnná,\n"
    "  prvek pole apod., tj. L-hodnota).\n"
    "- Argumentem je typicky výraz (&proměnná) nebo proměnná typu ukazatel\n"
    "  obsahující adresu existující paměťové buňky (proměnné apod.).\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Příklad\n"
    "- Procedura pracuje s originálními argumenty pomocí dereferenčního operátoru (*).\n"
    "- Taková změna se projeví i vně podprogramu. Nemění se zde totiž hodnota\n"
    "  parametrů samotných, ale původní proměnné, na které parametry odkazují.\n"
    "\n"
    "  void zamena(float *a, float *b)\n"
    "  {\n"
    "    float c = *a; // Místo a používáme *a, místo b pak *b.\n"
    "    *a = *b;      // a obsahuje adresu původní proměnné, *a je původní proměnná\n"
    "    *b = c;\n"
    "  }\n"
    "\n"
  );

  if (navratDoMenu()) return;

//  zamena(3.1, 4.0+0.5); // Tohle nejde, je to syntaktická chyba!
  float m = 3.1, n = 4.5;
  zamena(&m, &n);       // Vymění hodnoty m a n. Pozor na referenční operátor &.


  printg(
    "\n"
    "Volání s předáváním odkazem\n"
    "\n"
    "  zamena(3.1, 4.0+0.5); // Tohle nejde, je to syntaktická chyba!\n"
    "  float m = 3.1, n = 4.5;\n"
    "  zamena(&m, &n);       // Vymění hodnoty m a n. Pozor na referenční operátor &.\n"
    "  => m: %g, n: %g     // Proměnné m, n teď mají vyměněné hodnoty.\n"
    "\n"
    , m, n
  );

  if (navratDoMenu()) return;

  m = 1.1, n = 5.5;
  float *pm = &m;     // Proměnná pm obsahuje adresu proměnné m.
  float *pn = &n;     // Proměnná pn obsahuje adresu proměnné n.
  zamena(pm, pn);     // Teď se změní m a n, ale pm a pn zůstanou nezměněné.

  printg(
    "\n"
    "Alternativní způsob\n"
    "\n"
    "  m = 1.1, n = 5.5;\n"
    "  float *pm = &m;     // Proměnná pm obsahuje adresu proměnné m.\n"
    "  float *pn = &n;     // Proměnná pn obsahuje adresu proměnné n.\n"
    "  zamena(pm, pn);     // Teď se změní m a n, ale pm a pn zůstanou nezměněné.\n"
    "  => m: %g, n: %g   // Proměnné m, n teď mají vyměněné hodnoty.\n"
    "\n"
    , m, n
  );

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Ukázková procedura demonstrující situaci, kdy se parametr předávaný
 * odkazem předává do dalšího podprogramu, který opět očekává odkaz.
 *
 * Tato procedura provede seřazení tří hodnot od nejmenší po největší. Parametry
 * se do této procedury předávají odkazem. Využívá k tomu proceduru zamena
 * (viz výše), která také očekává parametry předané odkazem.
 *
 * Pokud v takovém podprogramu pracujeme s hodnotou na níž parametr ukazuje,
 * musíme používat výraz s dereferenčním operátorem (*a, *b, *c).
 *
 * Pokud potřebujeme takový parametr předat odkazem do jiného podprogramu, pak
 * žádný operátor není potřeba - podprogram očekává ukazatel a parametr je
 * ukazatel, proto jej předáme přímo (a, b, c).
 *
 * Pokud bychom trvali na použití referenčního operátoru &, museli bychom
 * předávat výraz, kde by byla kombinace obou operátorů: &*a. Tyto operátory
 * se ale vzájemně vyruší, takže je to totéž, jako když napíšeme rovnou: a.
 *
 *
 * \param a float* Parametr předávaný odkazem.
 * \param b float* Parametr předávaný odkazem.
 * \param c float* Parametr předávaný odkazem.
 */
void serad3(float *a, float *b, float *c)
{
  if (*a > *b)     // Tady musí být *a, *b, protože nám jde o hodnoty
    zamena(a, b);  // Proměnné a, b obsahují ukazatele, které se tu očekávají.
  if (*b > *c)
    zamena(b, c);
  if (*a > *b)
    zamena(&*a, &*b); // Názorná ukázka, co se děje.
}

void odkazemUvnitrFunkce(void)
{
  printg(
    "******************************************\n"
    "** Předávání odkazem uvnitř podprogramu **\n"
    "\n"
    "- Pozor na vnořené předávání odkazem.\n"
    "\n"
    "Ukázka\n"
    "- Procedura zamena zamění hodnoty zadaných proměnných.\n"
    "\n"
    "  void zamena(float *a, float *b)\n"
    "  {\n"
    "    float c = *a; // Místo a používáme *a, místo b pak *b.\n"
    "    *a = *b;      // a obsahuje adresu původní proměnné, *a je původní proměnná\n"
    "    *b = c;\n"
    "  }\n"
    "\n"
    "- Procedura serad3 seřadí hodnoty tří proměnných pomocí funkce zamena.\n"
    "\n"
    "  void serad3(float *k, float *l, float *m)\n"
    "  {\n"
    "    if (*k > *l)     // Tady musí být *k, *l, protože nám jde o hodnoty.\n"
    "      zamena(k, l);  // Proměnné k, l obsahují ukazatele, které se tu očekávají.\n"
    "    if (*l > *m)\n"
    "      zamena(l, m);  // Použití zamena(&l, &m); by zde byla hrubá chyba!\n"
    "    if (*a > *b)\n"
    "      zamena(&*k, &*l); // Názorná ukázka, co se děje.\n"
    "  }\n"
    "\n"
  );
  if (navratDoMenu()) return;
  printg(
    "\n"
    "Vysvětlení\n"
    "- V proceduře serad3 voláme zamena(k, l), nikoli zamena(&k, &l), protože\n"
    "  procedura zamena očekává argument typu float* a proměnné k, l už tohoto\n"
    "  typu jsou.\n"
    "- Výraz &k by vrátil adresu proměnné k, nikoli adresu původní proměnné,\n"
    "  která byla zadána při volání procedury serad3 a je uložena v proměnné k.\n"
    "- Použití výrazu &*k je také možné, ale je to poněkud mechanické.\n"
    "  Operátory & a * se tady vzájemně vyruší.\n"
    "\n"
  );
  if (navratDoMenu()) return;

  float a = 1.7, b = 5.2, c = -0.5;
  serad3(&a, &b, &c);

  printg(
    "\n"
    "Ukázka použití\n"
    "  float a = 1.7, b = 5.2, c = -0.5;\n"
    "  serad3(&a, &b, &c);\n"
    "  => a: %g, b: %g, c: %g\n"
    "\n"
    , a, b, c
  );

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}



///////////////////////////////////////////////////////////////////////////

/** \brief Funkce vracející faktoriál zadaného argumentu.
 *
 * Funkce počítá faktoriál pomocí rekurzivního předpisu:
 * n! = 1, když n == 0
 *    = n * (n - 1)!, když n > 0
 *
 * Rekurzivní výpočet se skládá ze zanořovací fáze a z fáze vynořování.
 * Při zanořování se pro každé znovuzavolání funkce vytvoří na zásobníku nový
 * prostor, kde leží nové kopie parametrů a nové lokální proměnné.
 * Koncová podmínka ukončuje pouze fázi zanořování, nikoli celý výpočet.
 * Pak ještě následuje fáze vynořování z rekurze, kdy se zpracovávají
 * mezivýsledky uchované na zásobníku během fáze zanořování.
 *
 * Zde se v zanořovací fázi postupně na zásobník ukládají hodnoty n, které
 * se postupně zmenšují o jedničku až k hodnotě 0. Poté se funkce začne postupně
 * vynořovat z rekurze a začne jimi násobit postupně získávané funkční hodnoty.
 * Teprve v posledním kroku funkce vrátí volajícímu podprogramu výslednou
 * hodnotu.
 *
 * \param n unsigned long long Parametr faktoriálu.
 * \return unsigned long long Vrací faktoriál zadaného n.
 */
unsigned long long faktorialR(unsigned long long n)
{
  if (n == 0)   // Koncová podmínka rekurze
    return 1;
  return n * faktorialR(n - 1); // Nezapomeň na return!
}

/** \brief Funkce vracející faktoriál zadaného argumentu.
 *
 * V tomto případě je faktoriál počítán pomocí obyčejného cyklu, nikoli rekurze.
 *
 * Protože teď není potřeba alokovat a rušit místo na zásobníku, je výpočet
 * rychlejší a potřebuje méně paměti.
 *
 * Algoritmus pro výpočet faktoriálu lze přepsat na cyklus velmi jednoduše,
 * protože v rekurzivním předpisu je rekurzivní volání až úplně na konci
 * (tzv. koncová rekurze - resp. po drobné úpravě by jí byla). Algoritmy, které
 * dělají důležité kroky před i po rekurzivním volání nebo dokonce používají
 * rekurzi vícekrát, nejde na cyklus převést tak snadno. U nich je obvykle
 * potřeba vyrobit si vlastní pomocnou datovou strukturu nahrazující implicitní
 * zásobník, který používá mechanismus volání funkcí.
 *
 * \param n unsigned long long Parametr faktoriálu.
 * \return unsigned long long Vrací faktoriál zadaného n.
 */
unsigned long long faktorialC(unsigned long long n)
{
  unsigned long long vysledek = 1;

  for (unsigned long long i = 1; i <= n; ++i)
  {
    vysledek *= i;
  }
  return vysledek;
}

void rekurze(void)
{
  printg(
    "*************\n"
    "** Rekurze **\n"
    "\n"
    "- Rekurzivní podprogram volá sám sebe.\n"
    "- Každá rekurze se dá přepsat pomocí cyklů. Některé problémy jsou\n"
    "  ale přehlednější, když jsou zapsány rekurzivně.\n"
    "- Musí obsahovat koncovou podmínku, která zamezí nekonečné rekurzi.\n"
    "\n"
    "Fáze rekurzivního výpočtu\n"
    "- Fáze zanořování\n"
    "  - Výpočet před rekurzivním voláním\n"
    "  - V paměti zvané zásobník se vytvoří lokální proměnné a kopie parametrů.\n"
    "- Koncová podmínka\n"
    "  - Musí být přítomna, jinak dojde k nekonečné rekurzi a havárii.\n"
    "  - Musí někdy sepnout - řídící proměnné k ní musí směřovat.\n"
    "  - Její sepnutí neukončuje výpočet! Ukončuje pouze fázi zanořování.\n"
    "- Fáze vynořování\n"
    "  - Výpočet za rekurzivním voláním\n"
    "  - Dochází k postupnému uvolňování záznamů v zásobníku.\n"
    "  - Postupně se započítávají mezivýsledky z parametrů a lokálních proměnných\n"
    "    ukládaných postupně na zásobník při zanořovací fázi.\n"
    "\n"
  );
  if (navratDoMenu()) return;

  unsigned long long vysledek = faktorialR(7);

  printg(
    "\n"
    "Ukázka - rekurzivní výpočet faktoriálu\n"
    "\n"
    "  unsigned long long faktorialR(unsigned long long n)\n"
    "  {\n"
    "    if (n == 0)   // Koncová podmínka rekurze\n"
    "      return 1;\n"
    "    return n * faktorialR(n - 1); // Nezapomeň na return!\n"
    "  }\n"
    "\n"
    "- Zde se při zanořování snižuje hodnota parametru n.\n"
    "- Koncová podmínka ukončí fázi zanořování.\n"
    "- Při vynořování se výsledky funkce postupně násobí řadou čísel uložených\n"
    "  v kopiích parametru n na zásobníku.\n"
    "\n"
    "  unsigned long long vysledek = faktorialR(7);\n"
    "  => vysledek: %lld\n"
    "\n"
    , vysledek
  );
  if (navratDoMenu()) return;

  vysledek = faktorialC(7);

  printg(
    "\n"
    "Ukázka - tentýž algoritmus zapsaný jako cyklus.\n"
    "\n"
    "  unsigned long long faktorialC(unsigned long long n)\n"
    "  {\n"
    "    unsigned long long vysledek = 1;\n"
    "  \n"
    "    for (int i = 1; i <= n; ++i)\n"
    "    {\n"
    "      vysledek *= i;\n"
    "    }\n"
    "    return vysledek;\n"
    "  }\n"
    "\n"
    "- Tato varianta je rychlejší než rekurze, protože spotřebuje mnohem méně\n"
    "  paměti - není zde zanořovací fáze.\n"
    "\n"
    "  vysledek = faktorialC(7);\n"
    "  => vysledek: %lld\n"
    "\n"
    , vysledek
  );

  if (navratDoMenu()) return;
  printg(
    "\n"
    "Pro další informace se podívej do zdrojového textu funkce %s.\n"
    , __func__
  );
  konecKapitoly();
}

