#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_population;
    do
    {
        start_population = get_int("Enter the starting population size (>= 9): ");
    }
    while (start_population < 9);

    // Prompt for the ending population size
    int end_population;
    do
    {
        end_population = get_int("Enter the ending population size (>= starting population size): ");
    }
    while (end_population < start_population);

    // Initialize years
    int years = 0;

    // Calculate the number of years required to reach the desired population
    while (start_population < end_population)
    {
        int births = start_population / 3;
        int deaths = start_population / 4;
        start_population = start_population + births - deaths;
        years++;
    }

    // Print the number of years required
    printf("Years: %d\n", years);

    return 0;
}
