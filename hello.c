#include<stdio.h>
#include<stdlib.h>

int main()
{
    int diff, year = 2023, month = 11, day = 19, n;
    printf("Please enter any number: ");
    scanf("%d", &n);
    struct {
        char id[10], name[20];
        struct {
            int day, month, year;
        } date;
    } employee[n];
    for(int i = 0; i < n; i++)
    {
        printf("Employee %d\n", i+1);
        printf("Please enter the name of the employee: ");
        scanf("%s", employee[i].name);
        fflush(stdin);
        printf("Please enter the employee id: ");
        scanf("%s", employee[i].id);
        printf("Please enter the day of joining: ");
        scanf("%d", &employee[i].date.day);
        printf("Please enter the month of joining: ");
        scanf("%d", &employee[i].date.month);
        printf("Please enter the year of joining: ");
        scanf("%d", &employee[i].date.year);
    }
    for(int i = 0; i < n; i++)
    {
        diff = year - employee[i].date.year;
        if(diff > 3)
            printf("Name: %s\n", employee[i].name);
        else if(diff == 3)
        {
            if(employee[i].date.month - month < 0)
                printf("Name: %s\n", employee[i].name);
            else if(employee[i].date.month - month == 0 && employee[i].date.day - day < 1)
                printf("Name: %s\n", employee[i].name);
        }
    }
    return 0;
}