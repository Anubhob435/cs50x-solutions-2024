#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototype to check if the key is valid
bool is_valid_key(string key);

// Function prototype to perform substitution
string substitute(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Store the key from the command-line argument
    string key = argv[1];

    // Check if the key is valid
    if (!is_valid_key(key))
    {
        printf("Invalid key\n");
        return 1;
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the key
    string ciphertext = substitute(plaintext, key);

    // Print the encrypted text
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to check if the key is valid
bool is_valid_key(string key)
{
    int key_length = strlen(key);

    // Check if the key has exactly 26 characters
    if (key_length != 26)
    {
        return false;
    }

    // Create an array to keep track of which letters have been used
    bool used[26] = {false};

    for (int i = 0; i < key_length; i++)
    {
        // Check if the character is an alphabetic character
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert the character to lowercase for indexing
        char letter = tolower(key[i]);

        // Check if the letter has already been used in the key
        if (used[letter - 'a'])
        {
            return false;
        }

        // Mark the letter as used
        used[letter - 'a'] = true;
    }

    return true;
}

// Function to perform substitution
string substitute(string plaintext, string key)
{
    int text_length = strlen(plaintext);
    string ciphertext = plaintext;

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char letter = islower(plaintext[i]) ? key[plaintext[i] - 'a'] : toupper(key[plaintext[i] - 'A']);
            ciphertext[i] = letter;
        }
    }

    return ciphertext;
}
