#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    char mas[a];
    scanf("%s", mas);

    int i = 0;
    int j = a - 1;
    int count = 0;
    while ((i < a / 2) && (j > i / 2))
    {
        if (count < 2)
        {
               if (mas[i] == mas[j])
               {
                   i++;
                   j--;
               }
               else
               {
                   count += 1;
                   j--;
               }
        }
        else
            break;
    }
    int new_count = count;
    if (count > 1)
    {
        i = 0;
        j = a - 1;
        count = 0;
        while ((i < a / 2) && (j > i / 2))
        {
            if (count < 2)
            {
                   if (mas[i] == mas[j])
                   {
                       i++;
                       j--;
                   }
                   else
                   {
                       count += 1;
                       i++;
                   }
            }
            else
                break;
        }
    }
    if (count == 0 | count == 1 | new_count == 0 |new_count == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

