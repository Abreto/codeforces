/* Codeforces Round #260 (Div. 1). Problem B - A Lot of Games, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

#define MAXT    100001
#define MAXALPHA    26

int n = 0, k = 0;
char str[MAXT] = {0};

char win[MAXT] = {0}, lose[MAXT] = {0};
int root = 0;
int trie[MAXT][MAXALPHA] = {{0}};
int ntrienode = 0;

int new_tire_node()
{
    return ++ntrienode;
}
int build_trie()
{
    int i = 0, l = strlen(str), v = root;
    for(i = 0;i < l;++i)
    {
        int alpha=str[i]-'a';
        if( 0 == trie[v][alpha] )
            trie[v][alpha] = new_tire_node();
        v = trie[v][alpha];
    }
}

void dfs(int v)
{
    int i = 0, to = 0;;
    char isleaf = 1;
    win[v] = 0; lose[v] = 0;
    for(i = 0;i < MAXALPHA;++i)
        if( 0 != (to = trie[v][i]) )
        {
            isleaf = 0;
            dfs(to);
            win[v] |= !(win[to]);
            lose[v] |= !(lose[to]);
        }
    if(isleaf)  lose[v]=1;
}

void answer(char x)
{
    puts(x ? "First" : "Second");
}

int main(void)
{
    int i = 0;

    scanf("%d%d", &n, &k);
    root = new_tire_node();
    for(i = 0;i < n;++i)
    {
        scanf("%s", str);
        build_trie();
    }
    dfs(root);

    if( 1 == k ) answer(win[root]);
    else if ( !(win[root]) ) answer(0);
    else if ( lose[root] ) answer(1);
    else if (k&1) answer(1);
    else answer(0);

    return 0;
}
