#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void warehouse();

struct program
{
    union products
    {
        struct handloom
        {
            int time_handloom;
            union bedroom
            {
                struct materess
                {
                    float weight;
                    float price[3];
                    char size[10];
                } materess;
                
                struct pillow
                {
                    char size[10];
                    float price[10];
                    char material[50];
                } pillow;
                
                struct bedsheet
                {
                    char size[10];
                    char color[50];
                    float price[10];
                } bedsheet;
            } bedroom;
        } handloom;

        struct electric
        {
            int time_electric;
            union appliance
            {
                struct headphones
                {
                    float price[3];
                    char color[10];
                } headphones;
                
                struct charger
                {
                    float price[3];
                    int power;
                    char cable_type[3];
                } charger;
                
                struct power_bank
                {
                    float price[3];
                    int capacity;
                } power_bank;
            } appliance;
        } electric;

        struct snacks
        {
            int time_snacks;
            union consumables
            {
                struct chocolate
                {
                    float price[3];
                    char type[10];
                    int quantity;
                } chocolate;
                
                struct chips
                {
                    float price[3];
                    char flavour[10];
                    int quantity;
                } chips;
                
                struct biscuits
                {
                    float price[3];
                    char flavour[10];
                    int quantity;
                } biscuits;
            } consumables;
        } snacks;

        struct groceries
        {
            int time_groceries;
            union eatery
            {
                struct flour
                {
                    float price[3];
                    int weight;
                    char type[100];
                } flour;
                
                struct milk
                {
                    float price[3];
                    char type_milk[100];
                    int quantity;
                } milk;
                
                struct fruits
                {
                    float price[3];
                    int weight;
                } fruits;
            } eatery;
        } groceries;

        struct toilet
        { 
            int time_toilet;
            union clean
            {
                struct soaps
                {
                    float price[3];
                    char fragrance[100];
                    int quantity;
                } soaps;
                
                struct toothpaste
                {
                    float price[3];
                    char type[100];
                    int quantity;
                } toothpaste;
                struct face_wash
                {
                    float price[3];
                    char properties[100];
                    int quantity;
                } face_wash;
            } clean;
        } toilet;

        struct shoe
        {
            union feet
            {
                struct sneaker
                {
                    float size;
                    int price[3];
                    char color[100];
                } sneaker;
                
                struct sport
                {
                    float size;
                    int price[3];
                    char color[100];
                } sport;
                
                struct sandal
                {
                    float size;
                    int price[3];
                    char color[100];
                } sandal;
            } feet;
        } shoe;
    } products;
} program;

int main()
{
    char username[25], password[50];
    printf("Please enter your details:\nUsername: ");
    gets(username);
    printf("Password: ");
    gets(password);
    if(!strcmp(username, "manager.warehouse") && !strcmp(password, "kartikagrawal"))
        warehouse();
    
}

void warehouse()
{
    printf("Hello Sir/Madam\nThe quantity of each item in warehouse is:\n");
    FILE *file = fopen("warehouse.txt", "r");
    if(file == NULL)
        printf("File not found");
    else
    {
        char data[50];
        while(fgets(data, sizeof(data), file))
            printf("%s\n", data);
    }
}