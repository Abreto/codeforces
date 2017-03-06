/* Codeforces Round #403 (Div. 2, based on Technocup 2017 Finals). Problem B - The Meeting Place Cannot Be Changed, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define EPS     (1e-9)
#define MAXN    60001
#define ABS(x)      (((x)>0)?(x):(-(x)))
#define MAX(a,b)    (((a)>(b))?(a):(b))
#define MIN(a,b)    (((a)<(b))?(a):(b))

int n = 0;
int x[MAXN] = {0};
int v[MAXN] = {0};

int check(double t)
{
    int i = 0;
    double flr = MAX((double)(x[0]) - t*v[0], 0.0), upb = (double)(x[0]) + t*v[0];
    for(i = 1;i < n;++i)
    {
        double tflr = MAX((double)(x[i]) - t*v[i], 0), tupb = (double)(x[i]) + t*v[i];
        if( tflr > flr ) flr = tflr;
        if( tupb < upb ) upb = tupb;
        if( upb < flr ) return 0;
    }
    return 1;
}

double solve(void)
{
    double l = 0.0, r = 1e9, mid = 0.0;
    while( ((r-l) > EPS) && ((r-l)/((r+l)/2.0) > EPS) )
    {
        mid = (r+l)/2.0;
        if( check(mid) )    r = mid;
        else                l = mid;
    }
    return mid;
}

int main(void)
{
    int i = 0;

    scanf("%d", &n);
    for(i = 0;i < n;++i)
        scanf("%d", x+i);
    for(i = 0;i < n;++i)
        scanf("%d", v+i);

    printf("%.12lf\n", solve());

    return 0;
}
