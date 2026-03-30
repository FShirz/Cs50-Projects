#include <cs50.h>
#include <stdio.h>

int h;
int main(void)
{
    do
    {
        // ask user for height
        h = get_int("Hight: ");
    }
    // the hight should be >= 1
    while (h <= 0);
    // the space between each line
    for (int i = 0; i < h; i++)
    {
        // the space before each cube
        for (int k = 0; k < h - (i + 1); k++)
        {
            printf(" ");
        }
        // print each cube
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
