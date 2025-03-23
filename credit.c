#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

long long get_card_number(void);
void split_and_reverse_digits(long long num, int digits[], int *size, int *first_two_digits);
int get_lunn_algo_sum(int digits[], int *size);
void get_card_type(int *first_two_digits);

int main()
{
    int digits[16];  // Assuming max 16-digit numbers
    int size;
    int first_two_digits;
    long long number = get_card_number();
    printf("Number: %lld\n", number);
    split_and_reverse_digits(number, digits, &size, &first_two_digits);
    int sum = get_lunn_algo_sum(digits, &size);
    if (sum%10 == 0)
    {
        printf("Card is VALID!\n");
        get_card_type(&first_two_digits);
    }
    else
    {
        printf("Card is INVALID!\n");
    }
}


long long get_card_number(void)
{
    long long number;
    int result;

    while (1)
    {
        printf("Enter card number: ");
        
        // Use fgets to read the input as a string
        char input[100];
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            continue;
        }

        // Remove newline character if it exists (this solves the extra blank line issue)
        input[strcspn(input, "\n")] = 0;

        // Check if the input is valid (only digits)
        int valid = 1;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]))  // If any character is not a digit
            {
                valid = 0;
                break;
            }
        }

        // If the input contains invalid characters
        if (!valid)
        {
            printf("Invalid input. Must only contain digits!\n");
            continue;  // Prompt the user again
        }

        // Convert the valid string input to a long long number
        result = sscanf(input, "%lld", &number);

        // If the conversion failed
        if (result != 1)
        {
            printf("Invalid input. Must only contain digits!\n");
            continue;
        }

        // If everything is valid, return the number
        return number;
    }
}

void split_and_reverse_digits(long long num, int digits[], int *size, int *first_two_digits)
{
    *size = 0;  
    *first_two_digits = 0;
    while (num > 0) {
        digits[*size] = num % 10;
        num /= 10;
        (*size)++;  
    }
    //first to digits:
    *first_two_digits = digits[*size-1]*10 + digits[*size-2];

    //printf("%i\n", *size);
}

int get_lunn_algo_sum(int digits[], int *size)
{
    int new_size = (*size + 1) / 2; 
    //printf("New size: %d\n", new_size);
    int new_arr[new_size];
    int new_arr_double[new_size];
    int new_arr_not_double[new_size];
    int j = 0;
    for (int i = 1; i < *size; i += 2)
    {
        new_arr[j] = digits[i];
        //printf("New array, j: %d, %d\n", new_arr[j], j);
        new_arr_double[j] = digits[i] * 2;
        //printf("New array double, j: %d, %d\n", new_arr_double[j], j);
        new_arr_not_double[j] = digits[i-1];
        //printf("New array not double, j: %d, %d\n", new_arr_not_double[j], j);
        j++;
    }
    // if odd number of digits:
    if (*size%2 != 0)
    {
        new_arr_not_double[j] = digits[*size - 1]; //last digit
    }


    int sum = 0;
    for (int i = 0; i < new_size; i++)
    {
        //printf("New array double: %d, %d\n", new_arr_double[i], i);
        if (new_arr_double[i]/10 == 0)
        {
            sum += new_arr_double[i];
            sum += new_arr_not_double[i];
        }
        else if (new_arr_double[i]/10 != 0)
        {
            sum += new_arr_double[i]/10 + new_arr_double[i]%10;
            sum += new_arr_not_double[i];
        }
        //printf("SUM = %d\n", sum);
    }
    return sum;
}

void get_card_type(int *first_two_digits)
{
    if (*first_two_digits == 34 || *first_two_digits == 37)
    {
        printf("AMEX\n");
    } else if (*first_two_digits == 51 || *first_two_digits == 52 ||*first_two_digits==53
     || *first_two_digits == 54 || *first_two_digits == 55)
     {
        printf(" MASTERCARD\n");
     }
     else
     {
        printf("VISA\n");
     }
    

}