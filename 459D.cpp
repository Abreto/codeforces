/* Codeforces Round #261 (Div. 2). D. Pashmak and Parmida's problem, by Abreto <m@abreto.net> */
#include <cstdio>
#include <map>

#define MAXN    1000001
#define lowbit(x)   ((x)&(-(x)))

using namespace std;

typedef long long int ll;

int n = 0;
int a[MAXN] = {0};
map<int, int> appear_times;
int c[MAXN] = {0}, d[MAXN] = {0}; /* c[i] = f(1,i,ai), d[j] = f(j,n,aj) */
int maxcd = 0;

int cou[MAXN] = {0};
int fen[MAXN] = {0};

void update(int d)
{
    cou[d] ++;
    while( d <= maxcd )
    {
        fen[d]++;
        d += lowbit(d);
    }
}

int sum(int c)
{
    int ret = -cou[c];
    while( c > 0 )
    {
        ret += fen[c];
        c -= lowbit(c);
    }
    return ret;
}

int main(void)
{
    int i = 0;
    ll ans = 0;

    scanf("%d", &n);
    for(i = 1;i <= n;++i)
        scanf("%d", a+i);

    /* generate c[i] .. */
    for(i = 1;i < n;++i)
    {
        c[i] = (++appear_times[a[i]]);
        if( c[i] > maxcd )  maxcd = c[i];
    }
    appear_times.clear(); /* .. and d[i]. */
    for(i = n;i > 1;--i)
    {
        d[i] = (++appear_times[a[i]]);
        if( d[i] > maxcd )  maxcd = d[i];
    }

    for(i = n;i > 1;i--)
    {
        update(d[i]);
        ans += sum(c[i-1]);
    }

    printf("%I64d\n", ans);
    return 0;
}

