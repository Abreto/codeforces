/* Codeforces Round #402 (Div.2). Problem A - Pupils Redistribution, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define ABS(x)  (((x)<0)?(-(x)):(x))

int main(void)
{
    int i = 0;
    int n = 0;
    int a[128] = {0}, b[128] = {0};
    int counta[6] = {0}, tot[6] = {0};
    int toexchage = 0;

    scanf("%d", &n);
    for(i = 0;i < n;++i)
    {
        scanf("%d", a+i);
        counta[a[i]]++;
        tot[a[i]]++;
    }
    for(i = 0;i < n;++i)
    {
        scanf("%d", b+i);
        tot[b[i]]++;
    }

    for(i = 1;i < 6;++i)
    {
        if( tot[i] & 1 )
            return !printf("-1");
        toexchage += ABS(tot[i]/2-counta[i]);
    }

    printf("%d\n", toexchage/2);
    return 0;
}
