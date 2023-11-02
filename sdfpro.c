#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void warehouse();
void display();
int delivery(int *);

struct program
{
    int total;
    int delivery_time;
    union products
    {
        struct handloom
        {
            union bedroom
            {
                struct mattress
                {
                    float weight;
                    float price[3];
                    char size[10];
                } mattress;
                
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
            union appliance
            {
                struct headphones
                {
                    float price;
                    char color;
                } headphones;
                
                struct charger
                {
                    float price;
                    int power;
                    char cable_type;
                } charger;
                
                struct power_bank
                {
                    float price;
                    int capacity;
                } power_bank;
            } appliance;
        } electric;

        struct snacks
        {
            union consumables
            {
                struct chocolate
                {
                    float price;
                    char type;
                    int quantity;
                } chocolate;
                
                struct chips
                {
                    float price;
                    char flavour;
                    int quantity;
                } chips;
                
                struct biscuits
                {
                    float price;
                    char flavour;
                    int quantity;
                } biscuits;
            } consumables;
        } snacks;

        struct groceries
        {
            union eatery
            {
                struct flour
                {
                    float price;
                    int weight;
                    char type_flour[25];
                } flour;
                
                struct milk
                {
                    float price;
                    char type_milk[25];
                    int quantity;
                } milk;
                
                struct fruits
                {
                    float price;
                    int weight;
                } fruits;
            } eatery;
        } groceries;

        struct toilet
        { 
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
                    int price;
                    char color[25];
                } sneaker;
                
                struct sport
                {
                    float size;
                    int price;
                    char color[25];
                } sport;
                
                struct sandal
                {
                    float size;
                    int price;
                    char color[25];
                } sandal;
            } feet;
        } shoe;
    } products;
} program;

int main()
{
    int main_choice, choice, sub_choice, index = 0, total[50], cart = 0, shop = 2, discount, time[50];
    char username[25], password[50], brand[50][25], address[100], mobile[15];
    time[0] = -1;
    printf("Please enter your details:\nUsername: ");
    gets(username);
    printf("Password: ");
    gets(password);

    if(!strcmp(username, "manager") && !strcmp(password, "hahaha"))
    {
        warehouse();
        exit(0);
    }
    
    else if(!strcmp(username, "employee") && !strcmp(password, "hihihi"))
    {
        display();
        exit(0);
    }
   
    printf("\nItems available today are:\nSnacks: Chips, Biscuits and Chocolates\n");
    printf("Groceries: Milk, Flour and Fruits\n");
    printf("Electronics: Headphones, Chargers and Power Banks\n");
    printf("Footwear: Sport shoes, Sneakers and Sandals\n");
    printf("Handloom: Bedsheets, Pillows and Matteresses\n");
    printf("Toiletries: Soaps, Face wash and Tooth Paste\n");
    
    do
    {
        printf("Enter 1 to buy Snacks\n");
        printf("Enter 2 to buy Groceries\n");
        printf("Enter 3 to buy Electronics\n");
        printf("Enter 4 to buy Footwear\n");
        printf("Enter 5 to buy Handloom products\n");
        printf("Enter 6 to buy Toiletries\n");
        printf("Enter: ");
        scanf("%d", &main_choice);
        switch(main_choice)
        {
            case 1:
            program.delivery_time = 1;
            printf("Enter 1 to buy Chips\n");
            printf("Enter 2 to buy Biscuits\n");
            printf("Enter 3 to buy Chocolates\n");
            printf("Enter: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Lays: 20rs\n");
                printf("Enter 2 to buy Doritos: 50rs\n");
                printf("Enter 3 to buy Bingo: 20rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the number of chips you want: ");
                scanf("%d", &program.products.snacks.consumables.chips.quantity);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Lays");
                    program.products.snacks.consumables.chips.price = 20;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Doritos");
                    program.products.snacks.consumables.chips.price = 50;
                }
                else
                {
                    strcpy(brand[index], "Bingo");
                    program.products.snacks.consumables.chips.price = 20;
                }
                program.total = program.products.snacks.consumables.chips.price * program.products.snacks.consumables.chips.quantity;
                break;
                
                case 2:
                printf("Enter 1 to buy Oreo: 35rs\n");
                printf("Enter 2 to buy Dark Fantasy: 80rs\n");
                printf("Enter 3 to buy Parle-G: 25rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the number of biscuits you want: ");
                scanf("%d", &program.products.snacks.consumables.biscuits.quantity);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Oreo");
                    program.products.snacks.consumables.biscuits.price = 35;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Dark Fantasy");
                    program.products.snacks.consumables.biscuits.price = 80;
                }
                else
                {
                    strcpy(brand[index], "Parle-G");
                    program.products.snacks.consumables.biscuits.price = 25;
                }
                program.total = program.products.snacks.consumables.biscuits.price * program.products.snacks.consumables.biscuits.quantity;
                break;
                
                case 3:
                printf("Enter 1 to buy Dairy Milk: 50rs\n");
                printf("Enter 2 to buy Snickers: 50rs\n");
                printf("Enter 3 to buy 5-Star: 20rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the number of chocolates you want: ");
                scanf("%d", &program.products.snacks.consumables.chocolate.quantity);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Dairy Milk");
                    program.products.snacks.consumables.chocolate.price = 50;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Snickers");
                    program.products.snacks.consumables.chocolate.price = 50;
                }
                else
                {
                    strcpy(brand[index], "5-Star");
                    program.products.snacks.consumables.chocolate.price = 20;
                }
                program.total = program.products.snacks.consumables.chocolate.price * program.products.snacks.consumables.chocolate.quantity;
                break;
            }
            break;
            
            case 2:
            program.delivery_time = 1;
            printf("Enter 1 to buy Milk\n");
            printf("Enter 2 to buy Flour\n");
            printf("Enter 3 to buy Fruits\n");
            printf("Enter: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Mother Dairy: 32rs\n");
                printf("Enter 2 to buy Amul: 78rs\n");
                printf("Enter 3 to buy Humpy: 49rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the number of packets you want: ");
                scanf("%d", &program.products.groceries.eatery.milk.quantity);
                printf("Enter the type of milk (Toned or Skimmed): ");
                gets(program.products.groceries.eatery.milk.type_milk);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Mother Dairy");
                    program.products.groceries.eatery.milk.price = 32;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Amul");
                    program.products.groceries.eatery.milk.price = 78;
                }
                else
                {
                    strcpy(brand[index], "Humpy");
                    program.products.groceries.eatery.milk.price = 49;
                }
                program.total = program.products.groceries.eatery.milk.price * program.products.groceries.eatery.milk.quantity;
                break;
                
                case 2:
                printf("Enter 1 to buy Fortune: 46rs per kg\n");
                printf("Enter 2 to buy Aashirvaad: 45rs per kg\n");
                printf("Enter 3 to buy Patanjali: 44rs per kg\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the weight of flour you want: ");
                scanf("%d", &program.products.groceries.eatery.flour.weight);
                printf("Enter the type of flour (Whole wheat or Multigrain or Both)");
                gets(program.products.groceries.eatery.flour.type_flour);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Fotune");
                    program.products.groceries.eatery.flour.price = 46;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Aashirvaad");
                    program.products.groceries.eatery.flour.price = 45;
                }
                else
                {
                    strcpy(brand[index], "Patanjali");
                    program.products.groceries.eatery.flour.price = 44;
                }
                program.total = program.products.groceries.eatery.flour.price * program.products.groceries.eatery.flour.weight;
                break;

                case 3:
                printf("Enter 1 to buy Apple: 172rs per kg\n");
                printf("Enter 2 to buy Guava: 118rs per kg\n");
                printf("Enter 3 to buy Pear: 324rs per kg\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the weight of fruits you want: ");
                scanf("%d", &program.products.groceries.eatery.flour.weight);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Apple");
                    program.products.groceries.eatery.fruits.price = 172;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Guava");
                    program.products.groceries.eatery.fruits.price = 118;
                }
                else
                {
                    strcpy(brand[index], "Pear");
                    program.products.groceries.eatery.fruits.price = 324;
                }
                program.total = program.products.groceries.eatery.fruits.price * program.products.groceries.eatery.fruits.weight;
                break;
            }
            break;

            case 3:
            program.delivery_time = 3;
            printf("Enter 1 to buy Headphones\n");
            printf("Enter 2 to buy Charger\n");
            printf("Enter 3 to buy Power Banks\n");
            printf("Enter: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Boat: 1700rs\n");
                printf("Enter 2 to buy Noise: 2000rs\n");
                printf("Enter 3 to buy JBL: 2900rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the color you want: ");
                gets(program.products.electric.appliance.headphones.color);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Boat");
                    program.products.electric.appliance.headphones.price = 1700;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Noise");
                    program.products.electric.appliance.headphones.price = 2000;
                }
                else
                {
                    strcpy(brand[index], "JBL");
                    program.products.electric.appliance.headphones.price = 2900;
                }
                program.total = program.products.electric.appliance.headphones.price;
                break;

                case 2:
                printf("Enter 1 to buy Samsung: 1700rs\n");
                printf("Enter 2 to buy Mi: 1000rs\n");
                printf("Enter 3 to buy One-Plus: 3000rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the power of charger you want: ");
                scanf("%d", &program.products.electric.appliance.charger.power);
                printf("Enter the type of cable you want: ");
                gets(program.products.electric.appliance.charger.cable_type);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Samsung");
                    program.products.electric.appliance.charger.price = 1700;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Mi");
                    program.products.electric.appliance.charger.price = 1000;
                }
                else
                {
                    strcpy(brand[index], "One-Plus");
                    program.products.electric.appliance.charger.price = 3000;
                }
                program.total = program.products.electric.appliance.charger.price;
                break;

                case 3:
                printf("Enter 1 to buy Mi: 2200rs\n");
                printf("Enter 2 to buy Ambrane: 1600rs\n");
                printf("Enter 3 to buy Amazon Basics: 2000rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the capacity you want: ");
                scanf("%d", &program.products.electric.appliance.power_bank.capacity);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Mi");
                    program.products.electric.appliance.power_bank.price = 1;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Ambrane");
                    program.products.electric.appliance.power_bank.price = 2;
                }
                else
                {
                    strcpy(brand[index], "Amazon Basics");
                    program.products.electric.appliance.power_bank.price = 2;
                }
                program.total = program.products.electric.appliance.power_bank.price;
                break;
            }
            break;

            case 4:
            program.delivery_time = 3;
            printf("Enter 1 to buy Sneakers\n");
            printf("Enter 2 to buy Sport Shoes\n");
            printf("Enter 3 to buy Sandals\n");
            printf("Enter: ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Red Tape: 1769rs\n");
                printf("Enter 2 to buy Adidas: 2647rs\n");
                printf("Enter 3 to buy Reebok: 1973rs\n");
                printf("Enter: ");
                scanf("%d", &sub_choice);
                printf("Enter the color you want: ");
                gets(program.products.shoe.feet.sneaker.color);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Red Tape");
                    program.products.shoe.feet.sneaker.price = 1769;
                }
            }
            break;
        }
        printf("Item successfully added to cart!\n");
        total[index] = program.total;
        time[index] = program.delivery_time;
        time[++index] = -1;
        cart += program.total;
        printf("Enter 1 to view your cart\n");
        printf("Enter 2 to continue shopping\n");
        printf("Enter: ");
        scanf("%d", &shop);
        if(shop == 1)
        {
            for(int i = 0; i < index; i++)
                printf("%s: %d\n", brand[i], total[i]);
            printf("Total value of cart: %d\n", cart);
            printf("Enter 1 to checkout\n");
            printf("Enter 2 to continue shopping\n");
            printf("Enter 3 to save the cart for later\n");
            printf("Enter: ");
            scanf("%d", &shop);
            if(shop == 1)
            {
                printf("Please enter additional details:\nAddress: ");
                gets(address);
                printf("Mobile Number: ");
                gets(mobile);
                discount = rand() % 10 + 1;
                printf("Amount Payable: %d", cart * discount / 100);
                printf("The least possible time to deliver is: %d", delivery(time));
            }
        }
    } while(shop == 2);
}

void warehouse()
{
    display();
    char data[50];
    FILE *file = fopen("warehouse.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char item[25], quantity[5], new_entry[50];
    printf("\nHello Sir/Madam\nPlease enter the name of the item bought: ");
    gets(item);
    printf("Please enter the total new quantity: ");
    gets(quantity);
    strcat(new_entry, item);
    strcat(new_entry, ": ");
    strcat(new_entry, quantity);
    while(fgets(data, sizeof(data), file))
    {
        if(strstr(data, item))
            fprintf(temp, "%s\n", new_entry);
        else
            fprintf(temp, "%s", data);
    }
    fclose(file);
    fclose(temp);
    remove("warehouse.txt");
    rename("temp.txt", "warehouse.txt");
    display();
}

void display()
{
    char data[50];
    FILE *file = fopen("warehouse.txt", "r");
    printf("Hello Sir/Madam\nThe quantity of each item in warehouse is:\n");
    if(file == NULL)
        printf("File not found");
    else
    {
        while(fgets(data, sizeof(data), file))
            printf("%s", data);
    }
    fclose(file);
}

int delivery(int *array)
{
    int max = *array;
    for(int i = 0; *(array + i) != -1; i++)
    {
        if(max < *(array + i))
            max = *(array + i);
    }
    return max;
}