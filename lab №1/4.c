#include<stdio.h>
#include <stdlib.h>



int main()
{
    int seasons_count, series_count, series_on_platform_count;
    scanf("%d %d %d", &seasons_count, &series_count, &series_on_platform_count);

    int seasons[seasons_count][series_count];

    for(int i = 0; i < seasons_count; i++) {
        for(int j = 0; j < series_count; j++) {
            seasons[i][j] = 0;
        }
    }

    for (int i = 0; i < series_on_platform_count; i++) {

        int season, series;

        scanf("%d %d", &series, &season);
        seasons[season - 1][series - 1] = 1;
    }

    int count = 0;

    for(int i = 0; i < seasons_count; i++) {
        for(int j = 0; j < series_count; j++) {
            if (seasons[i][j] == 0) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < seasons_count; i++)
    {
        for(int j = 0; j < series_count; j++) {
            if (seasons[i][j] == 0) {
                printf("%d %d\n", j+1, i+1);
            }
        }
    }

    return 0;
}
