#include <stdio.h>
#include <stdlib.h>

struct rates{
    long long id;
    long long rating;
};

void quick_sort(struct rates *arr, long long left, long long right, long long start)
{
    if(left >= right)
        return;
    long long middle = start;
    long long i = left;
    long long j = right;
    while (i <= j)
    {
        while (arr[i].rating < middle)
            i++;
        while (arr[j].rating > middle)
            j--;
        if (i <=j)
        {
            struct rates temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j, arr[(left + j - 1) / 2].rating);
    quick_sort(arr, i, right, arr[(i + right + 1) / 2].rating);


}


int main()
{
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    long long *kritick_znach = malloc(sizeof(long long) * n);
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &kritick_znach[i]);
    }
    struct rates sf[m];
    long long input;
    long long per_summa;
    for (long long i = 0; i < m; i++)
    {
        per_summa = 0;
        for (long long j = 0; j < n; j++)
        {
            scanf("%lld", &input);
            per_summa += input * kritick_znach[j];
        }
        sf[i].id = i + 1;
        sf[i].rating = (per_summa % 1000000007);
    }
    quick_sort(sf, 0, m - 1, sf[(m - 1) / 2].rating);

    long long answer[k][2];
    long long j = k - 1;
    for (long long i = m - 1; i > m - k - 1; i--)
    {
        answer[j][0] = sf[i].id;
        answer[j][1] = sf[i].rating;
        j--;
    }

    for (long long i = k - 1; i >= 0; i--)
    {
        //printf("%d %d\n", answer[i][0], answer[i][1]);
        long long x = m - k - 1;
        while (x >= 0)
        {
            if (sf[x].rating == answer[i][1])
            {
                if (sf[x].id < answer[i][0])
                {
                    long long temp_0 = answer[i][0];
                    answer[i][0] = sf[x].id;
                    sf[x].id = temp_0;
                }
                x--;
            }
            else
                break;
        }
    }
    for (long long i = k - 1; i > 0; i--)
    {
        long long x = k - 2;
        while (x >= 0)
        {
            if (answer[i][1] == answer[x][1])
            {
                if (answer[i][0] > answer[x][0])
                {
                    long long temp_0 = answer[i][0];
                    answer[i][0] = answer[x][0];
                    answer[x][0] = temp_0;
                }
                x--;
            }
            else
            {
                break;
            }
        }
    }

    for (long long i = k - 1; i >= 0; i--)
    {
        printf("%lld ", answer[i][0]);
    }

    return 0;
}
