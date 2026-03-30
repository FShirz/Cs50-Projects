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
    // the hight should be >1 and <8
    while (h < 1 || h > 8);
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
        // print the space between pyramids
        printf("  ");
        // print the second cube serie
        for (int x = 0; x < i + 1; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
