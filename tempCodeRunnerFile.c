#include<stdio.h>
#include<stdlib.h>

void input(int, struct bank[]);
struct bank {
        unsigned long accno;
        char name[10];
        int balance;
    };
int main()
{
    int n, choice, amount, account;
    printf("Please enter any number less than or equal to 20: ");
    scanf("%d", &n);
    struct bank customer[n];
    input(n, customer);
    printf("1. Print the Account number and name and balance of each customer\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Search Customer\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        for(int i = 0; i < n; i++)
        {
            printf("Customer %d\n", i+1);
            printf("Name: %s\n", customer[i].name);
            printf("Account NUmber: %d\n", customer[i].accno);
            printf("Balance: %d\n", customer[i].balance);
        }
        break;
        case 2:
        printf("Please enter your account number: ");
        scanf("%d", &account);
        for(int i = 0; i < n; i++)
        {
            if(account == customer[i].accno)
            {
                jump:
                printf("Please enter the amount you want to withdraw: ");
                scanf("%d", &amount);
                if(amount > customer[i].balance)
                    goto jump;
                customer[i].balance -= amount;
                break;
            }
        }
        break;
        case 3:
        printf("Please enter your account number: ");
        scanf("%d", &account);
        for(int i = 0; i < n; i++)
        {
            if(account == customer[i].accno)
            {
                printf("Please enter the amount you want to deposit: ");
                scanf("%d", &amount);
                customer[i].balance += amount;
                break;
            }
        }
        break;
        case 4:
        printf("Please enter your account number: ");
        scanf("%d", &account);
        for(int i = 0; i < n; i++)
        {
            if(account == customer[i].accno)
            {
                printf("Name: %s\n", customer[i].name);
                printf("Balance: %d\n", customer[i].balance);
                break;
            }
        }
        break;
    }
}
void input(int x, struct bank customer[])
{
    for(int i = 0; i < x; i++)
    {
        fflush(stdin);
        printf("Customer %d\n", i+1);
        printf("Please enter the name: ");
        gets(customer[i].name);
        printf("Please enter the account number: ");
        scanf("%d", &customer[i].accno);
        printf("Please enter the balance: ");
        scanf("%d", &customer[i].balance);
    }
}