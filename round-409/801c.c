/* Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2). Problem C, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <float.h>

#define N (100001)
#define EPS (1e-6)

typedef long long int ll;

int n = 0, p = 0;
int a[N] = {0};
int b[N] = {0};
ll suma = 0;

double dmax(double a, double b)
{
    return (a>b)?a:b;
}

int check(double t)
{
    int i = 0;
    double prest = p;
    for(i = 0;i < n;++i)
    {
        double dp = (double)(a[i]) - ((double)(b[i]))/t;
        if( dp < (1e-8) )
            continue;
        prest -= dp;
        if( prest < -(1e-8) )
            return 0;
    }
    return 1;
}

double solve(void)
{
    double l = 0.0, r = DBL_MAX; /* the answer lies in [l,r) */
    while( (r-l) > EPS || ((r-l)/dmax(1,r)) > EPS )
    {
        double mid = (l+r)/2;
        if( check(mid) )
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main(void)
{
    int i = 0;

    scanf("%d %d", &n, &p);
    for(i = 0;i < n;++i)
    {
        scanf("%d %d", a+i, b+i);
        suma += (ll)(a[i]);
    }

    if( p >= suma )
        printf("-1\n");
    else
        printf("%.9lf\n", solve());

    return 0;
}
