#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStringLength(char * str)
{
    int offset = 0;

    while (str[offset] != 0) {
        offset++;
    }

    return offset;
}

void copyString(char *from , char *to)
{
    int index = 0;

    while (from[index] != 0) {
        to[index] = from[index];
        index++;
    }
    to[index] = '\0';
}

void swap(char *x, char *y)
{
    char *temp = x;
    x = y;
    y = temp;
}

// my first thought solution
void reverseString(char *from, char *to)
{
    int i, n;
    n = strlen(from);
    
    for (i = 0; i <= n - 1; i++) {
        to[i] = from[n - i - 1];
    
    }
}

void reverse0(char *str)
{
    int n = strlen(str);
    
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void reverse1(char *str)
{
    int n = strlen(str);
    
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void reverse2(const char *s1, char *s2, size_t len)
{
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        s2[j] = s1[i];
    }
    s2[j] = '\0';
}

    
void reverse3(char *str)
{
    char *end = str + strlen(str) - 1;

    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

void reverse4(char *str, int length)
{
    if (length <= 1) return;

    char tmp = str[0];
    str[0] = str[length - 1];
    str[length - 1] = tmp;

    reverse4(str + 1, length - 2);
}

// MALLOC !!!!
char * reverse5(const char *str)
{
    int length = strlen(str);
    char *result = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        result[i] = str[length - 1 - i];
    }

    result[length] = 0;
    return result;
}

char * reverse6(const char *str)
{
    char *result = malloc(strlen(str) + 1);

    strcpy(result, str);
    reverse3(result);
    return result;
}



int main(int argc, char *argv[])
{
    char *str1 = "Hello World! I'am string 1.";
    char str2[] = "Hello World!";
    char newstring[500];

    printf("Hello World!\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s has length %d bytes\n", str1, getStringLength(str1));
    printf("%s has length %lu bytes\n", str1, strlen(str1));
    printf("Print a backslash \\ \n");
    copyString(str1, newstring);
    strcpy(newstring, str2);
    printf("%s\n\n", newstring);

    reverseString(str2, newstring);
    printf("Reversed String => %s\n", newstring);

    return EXIT_SUCCESS;
}
