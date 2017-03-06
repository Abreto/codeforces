/* Codeforces Round #403 (Div. 2, based on Technocup 2017 Finals). Problem A - Andryusha and Socks, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define MAXN    100001

int ifontable[MAXN] = {0};
int nontable = 0;

int main(void)
{
    int i = 0;
    int n = 0, xi = 0;
    int maxontable = 0;

    scanf("%d", &n);
    for(i = 0;i < 2*n;++i)
    {
        scanf("%d", &xi);
        if( ifontable[xi] )
            nontable--;
        else
        {
            ifontable[xi] = 1;
            nontable++;
            if(nontable > maxontable)
                maxontable = nontable;
        }
    }

    printf("%d\n", maxontable);
    return 0;
}
