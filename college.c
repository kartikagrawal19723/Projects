#include<stdio.h>
#include<stdlib.h>
int main()
{
    char name1[10], name2[10], name3[10];
    char path[] = "C:\\Users\\karti\\OneDrive\\Desktop\\";
    char path1[50], path2[50], path3[50], data[25];
    printf("Enter name of first file: ");
    scanf("%s", name1);
    fflush(stdin);
    printf("Enter name of second file: ");
    scanf("%s", name2);
    fflush(stdin);
    printf("Enter name to store merged file: ");
    scanf("%s", name3);
    strcpy(path1, path);
    strcpy(path2, path);
    strcpy(path3, path);
    strcat(path1, name1);
    strcat(path2, name2);
    strcat(path3, name3);
    FILE *file1 = fopen(path1, "r");
    FILE *file2 = fopen(path2, "r");
    FILE *file3 = fopen(path3, "a");
    while(fgets(data, sizeof(data), file1))
        fprintf(file3, "%s", data);
    while(fgets(data, sizeof(data), file2))
        fprintf(file3, "%s", data);
    printf("Two files merged %s successfully\n", name3);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}