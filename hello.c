#include<stdio.h>
int multiply(int, int);
int main()
{
    int a, b;
    printf("Please enter any two numbers:\n");
    scanf("%d%d", &a, &b);
    printf("Multiplication gives: %d\n", multiply(a, b));
    return 0;
}
int multiply(int x, int y)
{
    if(y == 1)
        return x;
    return x + multiply(x, --y);
}