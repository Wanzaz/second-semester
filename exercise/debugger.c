/*
 * Projekt: Debugger
 * Autor: Andrew
 * Datum: 14.9.2022
 */

#include <stdio.h>
#include <stdlib.h>


/**
    Pole my byt naplneno posloupnosti cisel 1, 2, 3, 4, ... 10
    Pomoci debugeru odladte s co nejmenším počtem zásahů do kódu, aby tomu opravdu tak bylo
**/


int funkce()
{
    int k=5, i=3;
    return (10-k+i*2);
}

void loadNumbers(int number, int array[])
{
    int i;
      for(int index=0;index<number;index++) {
          array[index] = index + 1;
      }
}

void show(int numbers, int array[])
{
    for (int index = 0; index < numbers; index++) {
        printf("%d ", array[index]);
    }
    printf("\n");
}

int main()
{
    int pole[10];
    int i, j, k, m=7;
    int velikost = 10;

    i=j=k=2;


    pole[m-i]=2+k;  // 5

    pole[pole[m-i]]= pole[m-i] +1; // 4

    pole[i=i-1] = k;  //1

    pole[pole[i]] = m=m-5;   //2

    pole[m-2] = i;  //0

    pole[j+i] = 3*k;   //3

    pole[3+pole[j+i]] = funkce(); //9

    pole[k=3*k] = 8;   //6

    pole[m*4] = pole[k] +1;   //8

    pole[7] = k + 3*i - 2*m;

    loadNumbers(velikost, pole);
    show(velikost, pole);


    return 0;
}
