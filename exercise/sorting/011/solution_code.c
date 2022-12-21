#include <stdio.h>
#include <stdlib.h>

// code written by teacher

typedef struct _osoba
{
  char jmeno[20+1];
  int vek;
} Tosoba;

typedef struct _pole
{
  Tosoba *prvek;
  int delka;
} TPoleOsob;

TPoleOsob * nactiOsoby(FILE *f)
{
  TPoleOsob * po = malloc(sizeof(TPoleOsob));
  if (po == NULL) return NULL;

  #define BLOK 32
  po->prvek = NULL;
  po->delka = 0;
  int i = 0;

  Tosoba o;

  while(fscanf(f, "%20s %d", o.jmeno,  &o.vek) == 2)
  {
    if (i == po->delka)
    {
      po->delka += BLOK;
      Tosoba * pom = realloc(po->prvek, po->delka*sizeof(Tosoba));
      if (pom == NULL)
      {
        return po;
      }
      po->prvek = pom;
    }
    po->prvek[i++] = o;
  }

  po->prvek = realloc(po->prvek, i*sizeof(Tosoba));
  po->delka = i;
  return po;
}


TPoleOsob * nactiOsoby100(FILE *f)
{
  #define MAXN 100
  TPoleOsob * po = malloc(sizeof(TPoleOsob));
  if (po == NULL) return NULL;
  po->prvek = malloc(MAXN*sizeof(Tosoba));
  if (po->prvek == NULL)
  {
    free(po); return NULL;
  }
  int i = 0;
  while(i < MAXN && fscanf(f, "%20s %d", po->prvek[i].jmeno,  &po->prvek[i].vek) == 2)
  {
    i += 1;
  }

  po->delka = i;
  return po;
}

static inline
void vymena(Tosoba *pole, int a, int b)
{
  Tosoba pom = pole[a];
  pole[a] = pole[b];
  pole[b] = pom;
}

void roztridPole(TPoleOsob *osoby, int pivot)
{
  int levy = 0, pravy = osoby->delka-1;
  while(levy < pravy)
  {
    while(levy < pravy && osoby->prvek[levy].vek <= pivot) levy += 1;
    while(levy < pravy && osoby->prvek[pravy].vek >= pivot) pravy -= 1;

    if (levy >= pravy) return;

    vymena(osoby->prvek, levy++, pravy--);
  }
}

void zapisPole(FILE * f, TPoleOsob * osoby)
{
  rewind(f);

  for (int i = 0; i < osoby->delka ; ++i)
  {
    fprintf(f, "%s %d\n", osoby->prvek[i].jmeno, osoby->prvek[i].vek);
  }
}

void roztridSoubor(FILE *f, int mez)
{
  TPoleOsob * osoby = nactiOsoby(f);
  if (osoby == NULL) return;

  roztridPole(osoby, mez);
  zapisPole(f, osoby);
}


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  printf("Zadej jmeno souboru: ");
  char cesta[255+1];
  scanf("%255s", cesta);

  printf("Zadej hodnotu pivota: ");
  int pivot;
  scanf("%d", &pivot);

  FILE * f = fopen(cesta, "r+");
  roztridSoubor(f, pivot);

  fclose(f);
  return 0;
}

