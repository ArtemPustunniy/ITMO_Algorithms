#include <stdio.h>
#include <string.h>

char input[1024];
int len;

int find_mistake(){
    int i, mistake = 0;
    for (i = 0; i < len; i ++)
        if (input[i] == '1')
            mistake ^= i + 1;
    return mistake;
}
int main(){
    int counter;
    scanf("%d", &counter);
    for (int q = 0; q < counter; q++){
        int i, mistake;
        char info[1024];
        int info_pos = 0;
        int b = 1;
        scanf("%s", input);
        len = strlen(input);

        mistake = find_mistake();
        if (mistake)
        {
            input[mistake - 1] ^= '0' ^ '1';

        }
        for (i = 0; i < len; i++)
            if (i + 1 == b)
                b <<= 1;
            else
                info[info_pos++] = input[i];
        info[info_pos] = '\0';
        printf("%s\n", info);
    }
    return 0;
}
