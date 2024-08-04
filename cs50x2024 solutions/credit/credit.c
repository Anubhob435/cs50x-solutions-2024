#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card_number;

    // Prompt the user for a credit card number
    do
    {
        card_number = get_long("Enter your credit card number: ");
    }
    while (card_number <= 0);

    long long temp = card_number;
    int sum = 0;
    int digit_count = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;
        digit_count++;

        // Calculate the checksum as per Luhn's Algorithm
        if (digit_count % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
    }

    // Check if the card number is valid and identify the card type
    if (sum % 10 == 0)
    {
        temp = card_number;

        // Determine the card type based on the number of digits and prefixes
        while (temp >= 100)
        {
            temp /= 10;
        }

        if ((temp == 34 || temp == 37) && digit_count == 15)
        {
            printf("AMEX\n");
        }
        else if ((temp >= 51 && temp <= 55) && digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((temp >= 40 && temp <= 49) && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
