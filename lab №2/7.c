#include <stdio.h>
#include <stdlib.h>

struct dedlines{
    long long first;
    long long second;
};
struct answers{
    long long answ_1;
    long long answ_2;
};


void Merge(struct dedlines *arr, int left, int middle, int right)
{
    int it_1 = 0;
    int it_2 = 0;
    struct answers ans[right - left];

    while((left + it_1 < middle) && (middle + it_2 < right))
    {
        if (arr[left + it_1].first < arr[middle + it_2].first)
        {
            ans[it_1 + it_2].answ_1 = arr[left + it_1].first;
            ans[it_1 + it_2].answ_2 = arr[left + it_1].second;
            it_1 += 1;
        }
        else
        {
            if (arr[left + it_1].first == arr[middle + it_2].first)
            {
                ans[it_1 + it_2].answ_1 = arr[middle + it_2].first;
                if (arr[left + it_1].second <= arr[middle + it_2].second)
                {
                    ans[it_1 + it_2].answ_2 = arr[left + it_1].second;
                    it_1 += 1;
                }
                else
                {
                    ans[it_1 + it_2].answ_2 = arr[middle + it_2].second;
                    it_2 += 1;
                }
            }
            else
            {
                ans[it_1 + it_2].answ_1 = arr[middle + it_2].first;
                ans[it_1 + it_2].answ_2 = arr[middle + it_2].second;
                it_2 += 1;
            }

        }
    }
    while (left + it_1 < middle)
    {
        ans[it_1 + it_2].answ_1 = arr[left + it_1].first;
        ans[it_1 + it_2].answ_2 = arr[left + it_1].second;
        it_1 += 1;
    }
    while (middle + it_2 < right)
    {
        ans[it_1 + it_2].answ_1 = arr[middle + it_2].first;
        ans[it_1 + it_2].answ_2 = arr[middle + it_2].second;
        it_2 += 1;
    }

    for(int i = 0; i < it_1 + it_2; i++)
    {
        arr[left + i].first = ans[i].answ_1;
        arr[left + i].second = ans[i].answ_2;
    }

}

void MergeSort(struct dedlines *arr, int left, int right)
{
    if (left + 1 >= right)
        return;
    int middle = (left + right) / 2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle, right);
    Merge(arr, left, middle, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct dedlines sf[n];
    for (int i = 0; i < n; i++)
    {
        long long input_first;
        long long input_second;
        scanf("%lld %lld", &input_first, &input_second);
        sf[i].first = input_first;
        sf[i].second = input_second;
    }
    MergeSort(sf, 0, n);
    /*printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", sf[i].first, sf[i].second);
    }*/


    long long count = 0;
    long long now = 0;
    int i = 0;
    while (i < n)
    {
        count += (sf[i].second - (sf[i].first + now));
        now += sf[i].first;
        i++;
    }
    printf("%lld", count);
    return 0;
}


