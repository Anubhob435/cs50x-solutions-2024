#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for input text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate the Coleman-Liau index
    int index = calculate_index(letter_count, word_count, sentence_count);

    // Determine and print the reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

// Function to count the number of letters in the text
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// Function to count the number of words in the text
int count_words(string text)
{
    int count = 0;
    bool in_word = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (!in_word)
            {
                in_word = true;
                count++;
            }
        }
        else
        {
            in_word = false;
        }
    }

    return count;
}

// Function to count the number of sentences in the text
int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

// Function to calculate the Coleman-Liau index
int calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}
