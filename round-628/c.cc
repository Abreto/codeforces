/* Codeforces Round #628 (Div. 2). Problem . */
#include <bits/stdc++.h>

using namespace std;

namespace abreto {

const int maxn = 100100;

int n;
int e[maxn];
/* to-node, e-id */
vector<int> g[maxn];

void color(void)
{
    int c = 0;
    memset(e, 0xff, sizeof(e));
    for (size_t i = 1; i <= n; ++i)
    {
        if (1 == g[i].size())
        {
            if (e[g[i][0]] >= 0) continue;
            e[g[i][0]] = c; c++;
        }
    }
    for (size_t i = 1; i < n; i++)
    {
        if (e[i] < 0)
        {
            e[i] = c; c++;
        }
    }
}

void main(void)
{
    cin >> n;
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    color();
    for (size_t i = 1; i < n; ++i)
    {
        cout << e[i] << '\n';
    }
}

}

int main(void)
{
    cin.sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    abreto::main();
    return 0;
}
