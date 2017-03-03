/* Codeforces Round #402 (Div.1). Problem A - String Game, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

#define MAXS    200001

int lt = 0, lp = 0;
char p[MAXS] = {0}, t[MAXS] = {0};
int a[MAXS] = {0};
int remainders[MAXS] = {0};
int nremainders = 0;

int check(void)
{
    int i = 0, j = 0;
    for(i = 0;i < lt;++i)
        if( remainders[i] )
        {
            if( t[i] == p[j] )
                j++;
            if( j == lp )
                return 1;
        }
    return 0;
}

void proc(void)
{
    int cur = lt;  /* cur indicates the last removing */
    int l = 0, r = 0, mid = 0; /* the answer lies in [l,r) */
    while( cur > 0 && nremainders < lp )
    {
        remainders[a[cur-1]-1] = 1;
        nremainders++;
        cur--;
    }

    l = 0; r = cur+1;
    while( l < r-1 )
    {
        mid = (l+r)/2;
        while(cur > mid)
        {
            remainders[a[--cur]-1] = 1;
            nremainders++;
        }
        while(cur < mid)
        {
            remainders[a[cur++]-1] = 0;
            nremainders--;
        }
        if( check() )
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
}

int main(void)
{
    int i = 0;

    scanf("%s", t); lt = strlen(t);
    scanf("%s", p); lp = strlen(p);
    for(i = 0;i < lt;++i)
        scanf("%d", a+i);
    proc();

    return 0;
}
