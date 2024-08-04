#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num1 = get_int("what is the first number? \n");
    int num2 = get_int("what is the second number? \n");

    if(num1 > num2)
    {
        printf("num 1 > num 2\n");
    }
    else if(num1 < num2)
    {
        printf("num 2 > num 1\n");
    }
    else
    {
        printf("num 1 = num 2\n");
    }
}