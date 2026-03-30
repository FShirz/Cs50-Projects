#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Number: ");
    int i = 0;
    long count = n;
    while (count > 0)
    {
        count = count / 10;
        i++;
    }
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    long x = n;
    int total = 0;
    do
    {
        mod1 = x % 10;
        x = x / 10;
        sum1 += mod1;

        mod2 = x % 10;
        x = x / 10;
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);

    total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long f2 = n;
    do
    {
        f2 = f2 / 10;
    }
    while (f2 > 100);

    if (i == 15)
    {
        if (f2 == 34 || f2 == 37)
        {
            printf("AMEX\n");
        }
    }
    if (i == 16)
    {
        if (f2 == 51 || f2 == 52 || f2 == 53 || f2 == 54 || f2 == 55)
        {
            printf("MASTERCARD\n");
        }
    }

    long f1 = n;
    do
    {
        f1 = f1 / 10;
    }
    while (f1 > 10);

    if (i == 13 || i == 16)
    {
        if (f1 == 4)
        {
            printf("VISA\n");
        }
    }
}
