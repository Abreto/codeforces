/* Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2). Problem B, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

typedef char bstr[128];

int main(void)
{
    int i = 0, len = 0;
    bstr x,y,z;

    scanf("%s", x);
    scanf("%s", y);
    len = strlen(x);

    for(i = 0;i < len;++i)
        if( x[i] < y[i] )
            return !printf("-1\n");
        else
            z[i] = y[i];
    z[i] = 0;

    printf("%s\n", z);
    return 0;
}
