#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
           scanf("%d", &arr[i]);
       }
    int high = (n < 32) ? n : 32;
    int min_res = 1000000000;
    for (int index = 0; index < high; index++)
    {
        unsigned int per = 0;
        unsigned int mask = arr[index];

        for (int j = index + 1; j < n; j++)
        {
            if ((mask & arr[j]) != 0) {
                mask = arr[j];
                per ++;
            } else mask = mask | arr[j];
        }
        for (int j = 0; j < index; j++)
        {
            if ((mask & arr[j]) != 0) {
                mask = arr[j];
                per ++;
            } else mask = mask | arr[j];
        }
        if (min_res > per)
            min_res = per;
    }
    if  (min_res == 0){
        min_res = 1;
        printf("%d",  min_res);
    }
    else
    {
        min_res ++;
        printf("%d", min_res);
    }

    return 0;


}
