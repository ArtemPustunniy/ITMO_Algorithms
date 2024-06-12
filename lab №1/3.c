#include <stdio.h>
#include <stdlib.h>

#define ll long long
int main()
{
    ll a;
    ll b;
    scanf("%lld %lld", &a, &b);
    while (a != b) {
        if (a > b) {
            ll tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    printf("%lld", a);
}
