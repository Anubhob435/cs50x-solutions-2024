#include <stdio.h>

int main()
{
    // Define a buffer to store the user's name
    char name[100];

    // Prompt the user for their name
    printf("What is your name? ");

    // Read the user's name from the standard input
    scanf("%99s", name);

    // Print a greeting message with the user's name
    printf("Hello, %s\n", name);

    return 0;
}
