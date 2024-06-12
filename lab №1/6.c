#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int mas[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        mas[i] = x;
    }

    long long int first_summa = 0;
    long long int last_summa = 0;

    for (int i = 1; i < n; i++)
    {
        first_summa += mas[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        last_summa += mas[i];
    }
    if (first_summa == 0)
    {
        printf("%d", 0);
        return 0;
    }
    if (last_summa == 0)
    {
        printf("%d", n - 1);
        return 0;
    }

    if (n > 3)
    {
        long long int right_summa = 0;
        for (int i = 2; i < n; i ++)
        {
            right_summa += mas[i];
        }
        long long int left_summa = mas[0];
        if (right_summa == left_summa)
        {
            printf("%d", 1);
        }
        else
        {
            int flug = 0;
            for (int i = 2; i < n - 1; i++)
            {
                left_summa = left_summa + mas[i - 1];
                right_summa = right_summa - mas[i];
                if (right_summa == left_summa)
                {
                    printf("%d", i);
                    flug = 1;
                    break;
                }
            }
            if (flug == 0)
            {
                printf("%d", -1);
            }
        }
    }
    else
    {
        if (n == 3)
        {
            if (mas[0] == mas[2])
                printf("%d", 1);
            else
                printf("%d", -1);
        }
        else
        {
            printf("%d", -1);
        }

    }



    return 0;
}
