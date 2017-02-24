/* Codeforces Round #401 (Div. 2). Problem D, by Abreto <m@abreto.net>. */
#include <iostream>
#include <string>

#define MAXN    500001
#define MIN(a,b)    (((a)<(b))?(a):(b))

using namespace std;

int n = 0;
string hashtags[MAXN];

int main(void)
{
    int i = 0, j = 0;
    ios::sync_with_stdio(false);

    cin>>n;
    for(i = 0;i < n;++i)
        cin>>(hashtags[i]);
    
    for(i = n-1;i > 0;--i)
    {
        int len = MIN(hashtags[i].length(),hashtags[i-1].length());
        if( 1 == len && 0 == hashtags[i][1] )
        {
            hashtags[i-1].erase(hashtags[i-1].begin()+1, hashtags[i-1].end());
            continue;
        }
        for(j = 0;j < len;++j)
            if( hashtags[i-1][j] > hashtags[i][j] )
                break;
            else if( hashtags[i-1][j] < hashtags[i][j] )
                goto nextpair;
        hashtags[i-1].erase(hashtags[i-1].begin()+j, hashtags[i-1].end());
nextpair:;
    }

    for(i = 0;i < n;++i)
        cout<<(hashtags[i])<<endl;

    return 0;
}
