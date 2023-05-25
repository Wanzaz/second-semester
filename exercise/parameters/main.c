#include <stdio.h>

void rectangle(float a, float b, float *circuit, float *content)
{
    *circuit = 2 * (a + b);
    *content = a * b;
}

void returnResults(float *r1, float *r2)
{
    rectangle(10.5, 6.7, r1, r2);
}


int main(int argc, char *argv[])
{
    float a, b, circuit, content;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &a);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &b);

    rectangle(a, b, &circuit, &content);

    printf("Circuit: %.2f\n", circuit);
    printf("Content: %.2f\n", content);

    returnResults(&circuit, &content);
    
    printf("Circuit: %.2f\n", circuit);
    printf("Content: %.2f\n", content);

    return 0;
}
