#include <stdio.h>
#include <stdlib.h>

#define ll long long

int main()
{
    ll n;
    long long int k;
    scanf("%lld %lld", &n, &k);
    long long int c[n];
    long long int newc[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &c[i]);
    }

    if (k > 0)
    {
            for (int j = 0; j < n; j++)
        {
            newc[(j + k) % n] = c[j];
        }
    }
    if (k < 0)
    {
        for (int j = 0; j < n; j++)
        {
            newc[j] = c[(j - k) % n];
        }
    }
    for (int i = 0; i < n; i++)
        {
            printf("%lld ", newc[i]);
        }

    return 0;
}


