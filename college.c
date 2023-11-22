#include<stdio.h>
int main()
{
    char file1[10], file2[10], file3[10], data[25];
    printf("Enter name of first file: ");
    scanf("%s", file1);
    printf("Enter name of second file: ");
    scanf("%s", file2);
    printf("Enter name to store merged file: ");
    scanf("%s", file3);
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *f3 = fopen(file3, "a");
    while(fgets(data, sizeof(data), f1))
        fprintf(f3, "%s", data);
    while(fgets(data, sizeof(data), f2))
        fprintf(f3, "%s", data);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Two files merged %s successfully\n", file3);
    return 0;
}