#include <cs50.h>
#include <stdio.h>

float average(int n, int scores[]);
int main(void)
{
    int n;
    do
    {
        n = get_int("How many scores? ");
    }
    while(n<1);

    int scores[n];

    for(int i=0; i<n; i++)
    {
        scores[i] = get_int("Enter the %i th score: ", i+1);
    }
    printf("The average is: %.2f\n", average(n,scores));

}
    float average(int n, int scores[])
    {
        int sum=0;
        for(int i = 0; i < n; i++)
        {
            sum += scores[i];
        }
        return sum / (float) n;
    }
