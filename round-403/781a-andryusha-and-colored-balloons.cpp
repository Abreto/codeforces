/* Codeforces Round #403 (Div. 1, based on Technocup 2017 Finals). Problem A - Andryusha and Colored Balloons, by Abreto <m@abreto.net>. */
#include <cstdio>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define MAXN    200001

int n = 0;
int color[MAXN] = {0};
map< int , vector<int> > conj;
int degree[MAXN] = {0};
int maxdegree = 0;
int mincolors = 0;
set<int> colors;

int visited[MAXN] = {0};
void pating(int i)
{
    if( !visited[i] )
    {
        visited[i] = 1;
        if( degree[i] > 1 )
        {
            set<int> t = colors;
            if( color[i] ) t.erase(color[i]);
            for(auto it=conj[i].begin();it != conj[i].end();++it)
            {
                if( color[*it] )
                    t.erase(color[*it]);
            }
            for(auto it=conj[i].begin();it != conj[i].end();++it)
            {
                if( !color[*it] )
                {
                    color[*it] = *(t.begin());
                    t.erase(t.begin());
                }
            }
            if( !color[i] ) color[i] = *(t.begin());
        }
        for(auto it=conj[i].begin();it != conj[i].end();++it)
            pating(*it);
    }
}

int main(void)
{
    int i = 0;
    int x = 0, y = 0;

    scanf("%d", &n);
    for(i = 0;i < n-1;++i)
    {
        scanf("%d %d", &x, &y);
        degree[x]++; degree[y]++;
        if( degree[x] > maxdegree ) maxdegree = degree[x];
        if( degree[y] > maxdegree ) maxdegree = degree[y];
        conj[x].push_back(y);
        conj[y].push_back(x);
    }
    mincolors = maxdegree+1;

    for(i = 1;i <= mincolors;++i) colors.insert(i);
    pating(1);

    printf("%d\n", mincolors);
    for(i = 1;i < n;++i)
        printf("%d ", color[i]);
    printf("%d\n", color[i]);
    return 0;
}
