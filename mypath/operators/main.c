#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Increment and Decrement operators
    int x, y;
    x = 5;
    y = 7;

    printf("value of x => %i\n\n", x);

    y = x++; // Y will receive the value that X used to be
             // it increments the value of x, but evaluates to the old value
    printf("y = x++; \n");
    printf("value of x => %i\n", x);
    printf("value of y => %i\n\n", y);

    y = ++x; // Y will receive the new value of x
    
    printf("y = ++x; \n");
    printf("value of x => %i\n", x);
    printf("value of y => %i\n", y);

    return EXIT_SUCCESS;
}
