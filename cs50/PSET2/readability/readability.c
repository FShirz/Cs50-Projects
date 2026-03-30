#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get input text

    string text = get_string("Text: ");

    float l = 0;
    float w = 1;
    float s = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // calculate the number of letters

        if (isalpha(text[i]) != 0)
        {
            l++;
        }

        // calculate the number of words

        if (text[i] == 32)
        {
            w++;
        }

        // calculate the number sentences

        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            s++;
        }
    }

    // calculate the Coleman-Liau index

    float L = 100 * l / w;
    float S = 100 * s / w;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print the results based on index

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
        printf("Grade %i\n", index);
    }
}
