#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file1 = fopen("sorted_numbers.txt", "w");
    FILE *file2 = fopen("random_numbers.txt", "w");
    if (file1 == NULL || file2 == NULL) {
        printf("ERROR Creating File!");
        exit(1);
    }

    for (int i = 0; i < 1000; ++i) {
      fprintf(file1, "%d\n", i);
    }

    for (int i = 0; i < 1000; ++i) {
      fprintf(file2, "%d\n", rand() % 30);
    }

    fclose(file1);
    fclose(file2);
    return (0);
}
