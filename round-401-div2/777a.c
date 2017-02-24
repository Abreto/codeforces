/* Codeforces Round #401 (Div. 2). Problem A, by Abreto <m@abreto.net>. */
#include <stdio.h>

/* 
0 - 1 - 2
0,1,2,2,1,0|0,...
1,0,0,1,2,2|1,...
2,2,1,0,0,1|2,...
 */

int position[3][6] = {
    {0,1,2,2,1,0},
    {1,0,0,1,2,2},
    {2,2,1,0,0,1}
};

int main(void)
{
    int i = 0;
    int n = 0, x = 0;

    scanf("%d %d", &n, &x);

    n %= 6;

    for(i = 0;i < 3;++i)
        if( position[i][n] == x )
            break;

    printf("%d\n", i);
    return 0;
}
