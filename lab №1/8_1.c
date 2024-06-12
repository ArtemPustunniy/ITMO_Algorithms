#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++){
           scanf("%d", &arr[i]);
       }

       unsigned int starts[5] = {0, 1, 2, 3};
       unsigned int min_res = 1000000000;

       for (int i = 0; i < 4; i++)
       {
           unsigned int first_per = starts[i];
           unsigned int mask = arr[starts[i]];
           unsigned int per = 0;
           unsigned int index = (starts[i] % n) + 1;
        while (index != first_per){

            if ((mask & arr[index]) != 0) {
                if(first_per == starts[i])
                   first_per = index;

                mask = arr[index];
                per += 1;
            } else mask = mask | arr[index];
            index++;
            index = index % n;
        }
        if (min_res > per)
            min_res = per;
    }

    if  (min_res == 0) min_res = 1;
        printf("%d",  min_res);

    return 0;
}


