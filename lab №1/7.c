#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    int count = 0;
    int mas[100000];
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int max_bal = 30;
        int min_bal = 15;
        //printf("%d\n", count);
        for (int j = 0; j < n; j++)
        {
            char sim;
            char sim_dop;
            int bal;
            getchar();
            scanf("%c%c %d", &sim, &sim_dop, &bal);
            if (sim == '>')
            {

                if ((bal >= min_bal) && (bal <= max_bal))
                {
                    min_bal = bal;
                }
                if ((bal >= min_bal) && (bal > max_bal))
                {
                    min_bal = -1;
                    max_bal = -1;
                }

                if (max_bal >= min_bal)
                {
                    //printf("%d\n", min_bal);
                    mas[count] = min_bal;
                    count = count + 1;
                }
                else
                {
                    min_bal = -1;
                    max_bal = -1;
                    mas[count] = -1;
                    count = count + 1;
                    //printf("%d", -1);
                }

            }
            else
            {
                if ((bal <= max_bal) && (bal >= min_bal))
                {
                    max_bal = bal;
                }
                if ((bal <= max_bal) && (bal < min_bal))
                {
                    min_bal = -1;
                    max_bal = -1;
                }

                if (max_bal >= min_bal)
                {

                    //printf("%d\n", min_bal);
                    mas[count] = min_bal;
                    count = count + 1;
                }
                else
                {
                    min_bal = -1;
                    max_bal = -1;
                    mas[count] = -1;
                    count = count + 1;
                    //printf("%d", -1);
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", mas[i]);
    }
    return 0;
}




