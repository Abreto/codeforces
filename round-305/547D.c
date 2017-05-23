/* Codeforces Round #305 (Div. 1). Problem D - Mike and Fish, by Abreto<m@abreto.net>. */
#include <stdio.h>

#define MAXN  200001

typedef struct
{
  int v;
  int n;
}edge_t;
int fe[MAXN];
edge_t et[MAXN<<1];
int net = 0;
void adde(int v1, int v2)
{
  et[++net].v = v2; et[net].n = fe[v1]; fe[v1] = net;
  et[++net].v = v1; et[net].n = fe[v2]; fe[v2] = net;
}

int n;
int xlastid[MAXN], ylastid[MAXN];
int xflag[MAXN], yflag[MAXN];
int color[MAXN];
int visited[MAXN];

void dfs(int v, int c)
{
  if(!visited[v])
  {
    int i = fe[v];
    visited[v] = 1;
    color[v] = c;
    while(i)
    {
      dfs(et[i].v, !c);
      i = et[i].n;
    }
  }
}

int main(void)
{
  int i = 0;
  int xi = 0, yi = 0;
  scanf("%d", &n);
  for(i = 1;i <= n;++i)
  {
    scanf("%d %d", &xi, &yi);
    if( xlastid[xi] > 0 && xflag[xi] )
      adde(xlastid[xi], i);
    if( ylastid[yi] > 0 && yflag[yi] )
      adde(ylastid[yi], i);
    xlastid[xi] = ylastid[yi] = i;
    xflag[xi] = !xflag[xi];
    yflag[yi] = !yflag[yi];
  }
  for(i = 1;i <= n;++i)
    dfs(i, 0);
  for(i = 1;i <= n;++i)
    printf("%c", color[i]?'b':'r');
  return puts(""),0;
}
