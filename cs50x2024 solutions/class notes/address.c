#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = "ANUBHOB!";
    printf("The address is %p\n", s);
    printf("The value stored in s is %s\n", s);
    printf("the addres of the first character of s is %p\n", &s[1]);
}