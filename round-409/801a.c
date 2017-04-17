/* Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2). Problem A, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

int count(char *s)
{
    int i = 0, l = strlen(s);
    int ret = 0;
    for(i = 0;i < l-1;i++)
        if( 'V' == s[i] && 'K' == s[i+1] )
        {
            ret++;i++;
        }
    return ret;
}

int mymax(int a, int b)
{
    return (a>b)?a:b;
}

int main(void)
{
    int i = 0;
    char str[128] = {0};
    int maxnvks = 0;

    scanf("%s", str);
    maxnvks = count(str);
    for(i = 0;i < strlen(str);++i)
        if('V' == str[i])
        {
            str[i] = 'K';
            maxnvks = mymax(maxnvks, count(str));
            str[i] = 'V';
        } else {
            str[i] = 'V';
            maxnvks = mymax(maxnvks, count(str));
            str[i] = 'K';
        }

    printf("%d\n", maxnvks);
    return 0;
}