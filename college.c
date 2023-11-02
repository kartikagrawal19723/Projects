#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    Sleep(10);
    printf("%d",rand() % 10 + 1);
}