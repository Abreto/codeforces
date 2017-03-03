/* Codeforces Round #402 (Div.2). Problem B - Werid Rounding, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char num[16] = {0};
    int ln = 0;
    int k = 0;

    scanf("%s %d", num, &k);
    ln = strlen(num);

    if( ln <= k )
        return !printf("%d\n", ln-1);
    else
    {
        int deleted = 0, zeros = 0;
        for(i = ln;i > 0 && zeros < k;--i)
            switch( num[i-1] )
            {
            case '0':
                zeros++;
                break;
            default:
                deleted++;
                break;
            }
        if( k == zeros )
            printf("%d\n", deleted);
        else
            printf("%d\n", ln-1);
    }

    return 0;
}
