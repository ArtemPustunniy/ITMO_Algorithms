#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x, y;
    scanf("%lld %lld", &x, &y);

    int counter = 0;
    for(int l = 1; l < 60; l++)
    {
        for(int m = 1; m < 60; m++)
        {
            for(int r = 1; r < 60; r++)
            {
                long long int total = (pow(2, l + m + r) - 1);
                long long int middle = (pow(2, m + r) - 1);
                long long int right = (pow(2, r) - 1);
                long long int res = (total) - (middle) + (right);
                if ((l + m + r) <= 60)
                {
                    if ((res >= x) && (res <= y))
                    {
                        counter++;
                    }
                }
                else if (res > y)
                {
                    break;
                }
            }
        }
    }
    printf("%d", counter);
    return 0;
}
