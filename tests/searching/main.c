#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char name[21];
    char author[21];
    int number_of_paiges;
    int price;
    int number_of_sold;

} Tbook;


int load(FILE *input, Tbook a[], int max_length) 
{
    int i = 0;
    while(i < max_length && 
            fscanf(input, "%20s %20s %d %d %d",
                a[i].name,
                a[i].author,
                &a[i].number_of_paiges,
                &a[i].price,
                &a[i].number_of_sold)== 5) {
        i++;
    }

    return i;
}

void printOut(FILE *output, Tbook a[], int length) 
{
    for(int i = 0; i < length; i++) {
        fprintf(output, "%s %s %d %d %d\n",
            a[i].name,
            a[i].author,
            a[i].number_of_paiges,
            a[i].price,
            a[i].number_of_sold);
    }
}

int findBook(Tbook a[], int n)
{
    int result_index = 0;
    int max_num_sold = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].number_of_paiges >= 300 && a[i].number_of_sold > max_num_sold) {
            result_index = i;
            max_num_sold = a[i].number_of_sold;
        }
    }

    if (max_num_sold == 0) {
        return -1;
    }
    
    return result_index;
}

static inline
void swap(Tbook *a, Tbook *b)
{
    Tbook temp = *b;
    *b = *a;
    *a = temp;
}

void sortBooks(Tbook a[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].number_of_sold > a[j + 1].number_of_sold) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    Tbook array[MAX];

    FILE *fbooks = fopen("books.txt", "r");
    if (fbooks == NULL) {
        printf("File cannot be opened\n");
        return -1;
    }

    int length = load(fbooks, array, MAX);
    printf("Number of books: %d\n", length);
    printf("---------------------\n");

    printOut(stdout, array, length);
    
    printf("---------------------\n\n");
    printf("SORTED BOOKS:\n");
    sortBooks(array, length);
    printOut(stdout, array, length);

    printf("---------------------\n\n");
    int result_index = findBook(array, length);
    printf("Searched Book: %s\n", array[result_index].name);

    
    fclose(fbooks);

    return 0;
}
