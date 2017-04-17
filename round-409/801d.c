/* Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2). Problem D, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <float.h>
#include <math.h>

#define MAXN    1024

int n = 0;
int x[MAXN], y[MAXN];
double ans = DBL_MAX;

double dis(int i, int j)
{
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return sqrt(dx*dx+dy*dy);
}

double area(int m)
{
    double x1 = x[m-1] - x[m], y1 = y[m-1] - y[m];
    double x2 = x[m+1] - x[m], y2 = y[m+1] - y[m];
    return fabs(x1*y2-x2*y1);
}

double f(int i)
{
    double s = area(i+1);
    double l = dis(i,i+2);
    return s/l/2.0;
}

int main(void)
{
    int i = 0;

    scanf("%d", &n);
    for(i = 0;i < n;++i)
        scanf("%d%d", x+i, y+i);
    x[n] = x[0]; y[n] = y[0];
    x[n+1] = x[1]; y[n+1] = y[1];

    for(i = 0;i < n;++i)
        ans = fmin(ans, f(i));

    printf("%.12lf\n", ans);
    return 0;
}
