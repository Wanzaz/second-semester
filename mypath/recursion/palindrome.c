#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *str, int start, int end)
{
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main(int argc, char *argv[])
{
    char *str = argv[1];
    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
