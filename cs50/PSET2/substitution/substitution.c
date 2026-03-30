#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cipher (string text, string key);
int main(int argc, string argv[])
{
    // end the program if argc is not 2, not only digit
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //end the program if argv doesn't consist of 26 characters
    else if ( strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //end the program if argv doesn't consist of letters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }
        //end the program if argv consists of the same letters
        for (int j = 0; j < n; j++)
        {
            if (toupper(argv[1][j]) == toupper(argv[1][i]) && i != j)
            {
                printf("You can't use a letter more than once.\n");
                return 1;
            }
        }
    }
    // get text
    string key = argv[1];
    string text = get_string ("plaintext:");
    return cipher(text, key);
    printf("\n");
    return 0;

}

int cipher (string text, string key)
{
    int value;
    char co;

    for (int k = 0, l = strlen(text); k < l; k++)
    {
        char c = text[k];
        printf("ciphertext:");
        if (isalpha(c) && isupper(c))
        {
            value = c - 65;
            co = toupper (key[value]);
        }
        else if (isalpha(c) && islower(c))
        {
            value = c - 97;
            co = tolower (key[value]);
        }
        else
        {
            co = c;
        }
        printf("%c", co);
    }
    printf("\n");
    return 0;

}
