/* Codeforces Beta Round 13. Problem E - Holes, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define MAXN    100001

#define ISDIGIT(x) ((x>='0')&&(x<='9'))
void readn(int *n)
{
    int c=0;*n=0;
    for(;!ISDIGIT(c);c=getchar());
    for(;ISDIGIT(c);c=getchar())*n=(*n)*10+c-'0';
}
void putn(int n)
{
    int ns[16]={0,n%10},nd=1;
    while(n/=10) ns[++nd]=n%10;
    while(nd) putchar(ns[nd--]+'0');
}

int N, M;
int power[MAXN];

void input_power(void)
{
    int i = 0;
    for(i = 1;i <= N;++i)
        readn(power+i);
}

void worker1(void)
{
    int i = 0, c = 0;
    input_power();
    for(i = 0;i < M;++i)
    {
        readn(&c);
        if(0 == c)
        {
            int a = 0, b = 0;
            readn(&a);readn(&b);
            power[a] = b;
        } else {
            int a = 0, la = 0;
            int cnt = 0;
            readn(&a);
            while(a <= N)
            {
                ++cnt;
                la = a;
                a = a + power[a];
            }
            printf("%d %d\n", la, cnt);
        }
    }
}

int chunk;
int count[MAXN];
int next[MAXN];

void set_chunk(void)
{
    chunk = 1;
    while((chunk*chunk) < N) chunk++;
}

void maintain(int i)
{
    int up = ((i-1)/chunk+1)*chunk;
    int ni = i+power[i];
    if(ni > N)
    {
        next[i]=i;
        count[i]=0;
    }
    else if(ni > up)
    {
        next[i]=ni;
        count[i]=1;
    }
    else
    {
        next[i]=next[ni];
        count[i]=1+count[ni];
    }
}

void init(void)
{
    int i = 0;
    input_power();
    for(i = N;i > 0;--i)
        maintain(i);
}

void worker2(void)
{
    int i = 0, c = 0;
    set_chunk();
    init();
    for(i = 0;i < M;++i)
    {
        readn(&c);
        if(0 == c)
        {
            int a = 0, b = 0;
            int floor = 0;
            readn(&a);readn(&b);
            power[a]=b;
            floor = ((a-1)/chunk)*chunk;
            for(;a > floor;--a)
                maintain(a);
        } else {
            int a = 0,cnt=0;
            readn(&a);
            while( a!=next[a] )
            {
                cnt+=count[a];
                a=next[a];
            }
            putn(a);putchar(' ');putn(cnt+1);puts("");
        }
    }
}

int main(void)
{

    readn(&N);readn(&M);
    if( N*M < 10000000 && N*M > 0 )
        worker1();
    else
        worker2();

    return 0;
}