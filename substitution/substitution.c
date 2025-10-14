#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';
            char cipher = toupper(key[index]);
            printf("%c", cipher);
        }
        else if (islower(c))
        {
            int index = c - 'a';
            char cipher = tolower(key[index]);
            printf("%c", cipher);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

bool valid_key(string key)
{
    int len = strlen(key);

    if (len != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';

        if (seen[index])
        {
            return false;
        }

        seen[index] = true;
    }

    return true;
}
