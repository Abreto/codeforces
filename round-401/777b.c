/* Codeforces Round #401 (Div. 2). Problem B, by Abreto <m@abreto.net>. */
#include <stdio.h>

int n = 0;
int ndigits[10] = {0};
char sherlock[1024] = {0};
char moriarty[1024] = {0};

/* return 1 if cannot */
int avoid_flick(int d)
{
    int i = 0;
    for(i = d;i < 10;++i)
        if( ndigits[i] > 0 )
        {
            ndigits[i]--;
            return 0;
        }
    for(i = 0;i < d;++i)
        if( ndigits[i] > 0 )
        {
            ndigits[i]--;
            return 1;
        }
}

/* return 1 if can */
int create_flick(int d)
{
    int i = 0;
    for(i = d+1;i < 10;++i)
        if( ndigits[i] > 0 )
        {
            ndigits[i]--;
            return 1;
        }
    for(i = 0;i <= d;++i)
        if( ndigits[i] > 0 )
        {
            ndigits[i]--;
            return 0;
        }
}

int main(void)
{
    int i = 0;
    int minimummget = 0;
    int maximumsget = 0;

    scanf("%d\n", &n);
    scanf("%s\n", sherlock);
    scanf("%s", moriarty);

    /* calculate minimum flicks m get. */
    for(i = 0;i < n;++i)
        ndigits[moriarty[i]-'0']++;
    for(i = 0;i < n;++i)
        minimummget += avoid_flick(sherlock[i]-'0');

    /* calculate maximum flicks s get. */
    for(i = 0;i < n;++i)
        ndigits[moriarty[i]-'0']++;
    for(i = 0;i < n;++i)
        maximumsget += create_flick(sherlock[i]-'0');

    printf("%d\n%d\n", minimummget, maximumsget);
    return 0;
}
