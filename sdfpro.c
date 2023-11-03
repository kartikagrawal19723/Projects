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
                    float price;
                    char size[10];
                } mattress;
                
                struct pillow
                {
                    char size[10];
                    float price;
                    char material[25];
                } pillow;
                
                struct bedsheet
                {
                    char size[10];
                    char color[25];
                    float price;
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
    int main_choice, choice, sub_choice, index = 0, total[50], cart = 0, shop = 2, discount, time[50], var;
    char username[25], password[50], brand[50][25], address[100], mobile[15];
    time[0] = -1;
    fflush(stdin);
    printf("Please enter your details:\nUsername: ");
    fflush(stdin);
    gets(username);
    fflush(stdin);
    printf("Password: ");
    fflush(stdin);
    gets(password);
    fflush(stdin);

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
        if(index == 50)
        {
            printf("Cart limit reached!\n");
            for(int i = 0; i < index; i++)
                printf("%s: %d\n", brand[i], total[i]);
            printf("Total value of cart: %d\n", cart);
            printf("Enter 1 to checkout\n");
            printf("Enter 2 to save the cart for later\n");
            fflush(stdin);
            printf("Enter: ");
            fflush(stdin);
            scanf("%d", &main_choice);
            fflush(stdin);
            if(main_choice == 1)
                goto checkout;
            else
                exit(0);
        }
        
        printf("Enter 1 to buy Snacks\n");
        printf("Enter 2 to buy Groceries\n");
        printf("Enter 3 to buy Electronics\n");
        printf("Enter 4 to buy Footwear\n");
        printf("Enter 5 to buy Handloom products\n");
        printf("Enter 6 to buy Toiletries\n");
        fflush(stdin);
        printf("Enter: ");
        fflush(stdin);
        scanf("%d", &main_choice);
        fflush(stdin);
        
        switch(main_choice)
        {
            case 1:
            program.delivery_time = 1;
            printf("Enter 1 to buy Chips\n");
            printf("Enter 2 to buy Biscuits\n");
            printf("Enter 3 to buy Chocolates\n");
            fflush(stdin);
            printf("Enter: ");
            fflush(stdin);
            scanf("%d", &choice);
            fflush(stdin);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Lays: 20rs\n");
                printf("Enter 2 to buy Doritos: 50rs\n");
                printf("Enter 3 to buy Bingo: 20rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the number of chips you want: ");
                fflush(stdin);
                scanf("%d", &program.products.snacks.consumables.chips.quantity);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the number of biscuits you want: ");
                fflush(stdin);
                scanf("%d", &program.products.snacks.consumables.biscuits.quantity);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the number of chocolates you want: ");
                fflush(stdin);
                scanf("%d", &program.products.snacks.consumables.chocolate.quantity);
                fflush(stdin);
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
            fflush(stdin);
            printf("Enter: ");
            fflush(stdin);
            scanf("%d", &choice);
            fflush(stdin);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Mother Dairy: 32rs\n");
                printf("Enter 2 to buy Amul: 78rs\n");
                printf("Enter 3 to buy Humpy: 49rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the number of packets you want: ");
                fflush(stdin);
                scanf("%d", &program.products.groceries.eatery.milk.quantity);
                fflush(stdin);
                printf("Enter the type of milk (Toned or Skimmed): ");
                fflush(stdin);
                gets(program.products.groceries.eatery.milk.type_milk);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the weight of flour you want: ");
                fflush(stdin);
                scanf("%d", &program.products.groceries.eatery.flour.weight);
                fflush(stdin);
                printf("Enter the type of flour (Whole wheat or Multigrain or Both)");
                fflush(stdin);
                gets(program.products.groceries.eatery.flour.type_flour);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the weight of fruits you want: ");
                fflush(stdin);
                scanf("%d", &program.products.groceries.eatery.flour.weight);
                fflush(stdin);
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
            fflush(stdin);
            printf("Enter: ");
            fflush(stdin);
            scanf("%d", &choice);
            fflush(stdin);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Boat: 1700rs\n");
                printf("Enter 2 to buy Noise: 2000rs\n");
                printf("Enter 3 to buy JBL: 2900rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the color you want: ");
                fflush(stdin);
                gets(program.products.electric.appliance.headphones.color);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the power of charger you want: ");
                fflush(stdin);
                scanf("%d", &program.products.electric.appliance.charger.power);
                fflush(stdin);
                printf("Enter the type of cable you want: ");
                fflush(stdin);
                gets(program.products.electric.appliance.charger.cable_type);
                fflush(stdin);
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
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the capacity you want: ");
                fflush(stdin);
                scanf("%d", &program.products.electric.appliance.power_bank.capacity);
                fflush(stdin);
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
            fflush(stdin);
            printf("Enter: ");
            fflush(stdin);
            scanf("%d", &choice);
            fflush(stdin);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Red Tape: 1769rs\n");
                printf("Enter 2 to buy Adidas: 2647rs\n");
                printf("Enter 3 to buy Reebok: 1973rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the color you want: ");
                fflush(stdin);
                gets(program.products.shoe.feet.sneaker.color);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Red Tape");
                    program.products.shoe.feet.sneaker.price = 1769;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Adidas");
                    program.products.shoe.feet.sneaker.price = 2647;
                }
                else
                {
                    strcpy(brand[index], "Reebok");
                    program.products.shoe.feet.sneaker.price = 1973;
                }
                program.total = program.products.shoe.feet.sneaker.price;
                break;

                case 2:
                printf("Enter 1 to buy Red Tape: 2009rs\n");
                printf("Enter 2 to buy Campus: 1449rs\n");
                printf("Enter 3 to buy Adidas: 1649rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the color you want: ");
                fflush(stdin);
                gets(program.products.shoe.feet.sport.color);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Red Tape");
                    program.products.shoe.feet.sport.price = 2009;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Campus");
                    program.products.shoe.feet.sport.price = 1449;
                }
                else
                {
                    strcpy(brand[index], "Adidas");
                    program.products.shoe.feet.sport.price = 1649;
                }
                program.total = program.products.shoe.feet.sport.price;
                break;

                case 3:
                printf("Enter 1 to buy Red Tape: 799rs\n");
                printf("Enter 2 to buy Bata: 837rs\n");
                printf("Enter 3 to buy Red Chief: 1637rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the color you want: ");
                fflush(stdin);
                gets(program.products.shoe.feet.sandal.color);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Red Tape");
                    program.products.shoe.feet.sandal.price = 799;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Bata");
                    program.products.shoe.feet.sandal.price = 837;
                }
                else
                {
                    strcpy(brand[index], "Red Chief");
                    program.products.shoe.feet.sandal.price = 1637;
                }
                program.total = program.products.shoe.feet.sandal.price;
                break;
            }
            break;

            case 5:
            program.delivery_time = 5;
            printf("Enter 1 to buy Mattress\n");
            printf("Enter 2 to buy Pillow\n");
            printf("Enter 3 to buy Bedsheet\n");
            printf("Enter: ");
            while((var = getchar()) != '\n' && var != EOF);
            scanf("%d", choice);
            while((var = getchar()) != '\n' && var != EOF);
            switch(choice)
            {
                case 1:
                printf("Enter 1 to buy Wakefit: 15520rs\n");
                printf("Enter 2 to buy Centuary: 22403rs\n");
                printf("Enter 3 to buy Sleepyhead: 14000rs\n");
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the size (Queen size or Single bed or King size): ");
                fflush(stdin);
                fgets(program.products.handloom.bedroom.mattress.size, sizeof(program.products.handloom.bedroom.mattress.size), stdin);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Wakefit");
                    program.products.handloom.bedroom.mattress.price = 15520;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "Centuary");
                    program.products.handloom.bedroom.mattress.price = 22403;
                }
                else
                {
                    strcpy(brand[index], "Sleepyhead");
                    program.products.handloom.bedroom.mattress.price = 14000;
                }
                program.total = program.products.handloom.bedroom.mattress.price;
                break;

                case 2:
                printf("Enter 1 to buy Beckham: 3200rs\n");
                printf("Enter 2 to buy SleepyCat: 1989rs\n");
                printf("Enter 3 to buy Wakefit: 1141rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the size (Large or Medium or Small): ");
                fflush(stdin);
                gets(program.products.handloom.bedroom.pillow.size);
                fflush(stdin);
                printf("Enter the material (Cotton or Feather or Synthetic): ");
                fflush(stdin);
                gets(program.products.handloom.bedroom.pillow.material);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Beckham");
                    program.products.handloom.bedroom.pillow.price = 3200;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "SleepyCat");
                    program.products.handloom.bedroom.pillow.price = 1989;
                }
                else
                {
                    strcpy(brand[index], "Sleepyhead");
                    program.products.handloom.bedroom.pillow.price = 1141;
                }
                program.total = program.products.handloom.bedroom.pillow.price;
                break;

                case 3:
                printf("Enter 1 to buy Homefab: 1200rs\n");
                printf("Enter 2 to buy BSB Home: 1300rs\n");
                printf("Enter 3 to buy Huesland: 1295rs\n");
                fflush(stdin);
                printf("Enter: ");
                fflush(stdin);
                scanf("%d", &sub_choice);
                fflush(stdin);
                printf("Enter the size (Large or Medium or Small): ");
                fflush(stdin);
                gets(program.products.handloom.bedroom.bedsheet.size);
                fflush(stdin);
                printf("Enter the color you want: ");
                fflush(stdin);
                gets(program.products.handloom.bedroom.bedsheet.color);
                fflush(stdin);
                if(sub_choice == 1)
                {
                    strcpy(brand[index], "Homefab");
                    program.products.handloom.bedroom.bedsheet.price = 1200;
                }
                else if(sub_choice == 2)
                {
                    strcpy(brand[index], "BSB Home");
                    program.products.handloom.bedroom.bedsheet.price = 1300;
                }
                else
                {
                    strcpy(brand[index], "Huesland");
                    program.products.handloom.bedroom.bedsheet.price = 1295;
                }
                program.total = program.products.handloom.bedroom.bedsheet.price;
                break;
            }
            break;

            case 6:
            
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
                checkout:
                printf("Please enter additional details:\nAddress: ");
                fflush(stdin);
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
    FILE *file = fopen("C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\warehouse.txt", "r");
    FILE *temp = fopen("C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\temp.txt", "w");
    char item[25], quantity[5], new_entry[50];
    fflush(stdin);
    printf("\nHello Sir/Madam\nPlease enter the name of the item bought: ");
    fflush(stdin);
    gets(item);
    fflush(stdin);
    printf("Please enter the total new quantity: ");
    fflush(stdin);
    gets(quantity);
    fflush(stdin);
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
    remove("C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\warehouse.txt");
    rename("C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\temp.txt", "C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\warehouse.txt");
    display();
}

void display()
{
    char data[50];
    FILE *file = fopen("C:\\Users\\karti\\OneDrive\\Documents\\GitHub\\Projects\\warehouse.txt", "r");
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