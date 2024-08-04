#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter the height of the pyramid (1-8): ");
    }
    while (height < 1 || height > 8);

    // Print the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces on the left
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print '#' on the right
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Print space in the middle
        printf("  ");

        // Print '#' on the right
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}