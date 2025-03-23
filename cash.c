#include <stdio.h>
#include <stdbool.h>

int get_positive_int(void);
int get_number_of_coins(int n);

int main() 
{ 

    int cash = get_positive_int();
    int change = get_number_of_coins(cash);
    
    printf("You change is: %d\n", change);  // Prints the entered number
    return 0;
}


int get_positive_int(void)
{
    int cash;
    printf("Enter an amount of cash: ");
    scanf("%d", &cash);  // "%d" is the format specifier for an integer
    if (cash < 0 ){
    printf("The amount must be positive!\n");
    printf("Enter an amount of cash: ");
    scanf("%d", &cash);  // "%d" is the format specifier for an integer
    }
    return(cash);
}

int get_number_of_coins(int cash)
{
    int change = 0;
    int coins[] = {25, 10, 5, 1}; // array of coins in case we decide to chage it
    int num_coins = sizeof(coins) / sizeof(coins[0]); // answers how many denominations we have?

    for (int i = 0; i < num_coins; i ++)
    {
        while (cash >= coins[i])
        {
            change ++;
            cash -= coins[i];
        }
    }
    return(change);
}