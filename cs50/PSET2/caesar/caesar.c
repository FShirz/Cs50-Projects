#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define your functions
bool only_digit(string s);
char rotate(char c, int n);
int main(int argc, string argv[])
{
    // end the program if argc is not 2, not only digit
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digit(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // get text
    string plain = get_string("plaintext: ");
    int n = atoi(argv[1]);
    printf("ciphertext: ");

    // print the function return
    for (int j = 0, l = strlen(plain); j < l; j++)
    {
        char c = plain[j];
        printf("%c", rotate(plain[j], n));
    }
    printf("\n");
    return 0;
}
// describe only digit function
bool only_digit(string s)
{
    // make a loop
    for (int i = 0, m = strlen(s); i < m; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
// describe rotate function
char rotate(char c, int n)
{
    char co = c;

    if (isalpha(c))
    {
        if (islower(c))
        {
            co = ((c - 'a' + n) % 26) + 'a';
        }
        else if (isupper(c))
        {
            co = ((c - 'A' + n) % 26) + 'A';
        }
    }
    else
    {
        co = c;
    }
    return co;
}
