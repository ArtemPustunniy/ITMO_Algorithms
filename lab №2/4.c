#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    scanf("%d", &len);
    int arr[len];
    for (int j = 0; j < len; j++)
    {
        arr[j] = j + 1;
    }

    for (int j = 2; j < len; j++)
    {
        int temp = arr[j];
        arr[j] = arr[j / 2];
        arr[j / 2] = temp;
    }

    for (int j = 0; j < len; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}
