#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Define the point values for each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Get words from players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner and print the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(string word)
{
    int score = 0;

    // Iterate through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char letter = word[i];

        // Check if the character is a letter (A-Z or a-z)
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            // Convert uppercase letters to lowercase for indexing the POINTS array
            if (letter >= 'A' && letter <= 'Z')
            {
                letter += ('a' - 'A');
            }

            // Calculate the score based on the letter's position in the alphabet
            score += POINTS[letter - 'a'];
        }
    }

    return score;
}
