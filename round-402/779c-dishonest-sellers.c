/* Codeforces Round #402 (Div.2). Problem C - Dishonest Sellers, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <stdlib.h>

#define MAXN    200001

int n = 0, k = 0;
int a[MAXN] = {0}, b[MAXN] = {0};
int delta[MAXN] = {0};
int tot = 0;

int compar(const void *a, const void *b)
{
    return ((*((int*)b)) - (*((int*)a)));
}

int main(void)
{
    int i = 0;

    scanf("%d %d", &n, &k);
    for(i = 0;i < n;++i)
        scanf("%d", a+i);
    for(i = 0;i < n;++i)
    {
        scanf("%d", b+i);
        tot += b[i];
        delta[i] = b[i] - a[i];
    }

    qsort(delta, n, sizeof(int), compar);

    for(i = 0;i < k;++i)
        tot -= delta[i];
    for(;delta[i] > 0;++i)
        tot -= delta[i];

    printf("%d\n", tot);
    return 0;
}
