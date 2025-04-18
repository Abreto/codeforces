#include <iostream>
#include <iomanip>
#include <cstdint>
#include <deque>
#include <utility>
#include <cassert>

using namespace std;

class Abreto
{
    typedef long long int ll;

    static constexpr int MAXN = 128, MAXM = 200020;

    int n, m, k, d;
    int a[MAXN][MAXM];

    ll min_cost[MAXN];
    deque<pair<int, ll>> min_q; // (pos, cost)
public:
    int solve(void)
    {
        int t;
        cin >> t;
        while (t--)
        {
            readinput();
            solvecase();
            clean();
        }
        return 0;
    }

    void readinput(void)
    {
        cin >> n >> m >> k >> d;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
    }

    void solvecase(void)
    {
        for (int i = 0;i < n; i++)
        {
            ll cost = 1;
            min_q.clear();
            min_q.emplace_back(0, 1);
            for (int j = 1; j < m; j++)
            {
                while (min_q.front().first < j - d - 1)
                {
                    min_q.pop_front();
                }
                assert(min_q.size() > 0);
                ll cur = min_q.front().second + a[i][j] + 1;
                while (!min_q.empty() && min_q.back().second >= cur)
                {
                    min_q.pop_back();
                }
                min_q.emplace_back(j, cur);
            }
            assert(min_q.back().first == m - 1);
            min_cost[i] = min_q.back().second;
        }

        ll ans = INT64_MAX, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += min_cost[i];
            if (i >= k)
                sum -= min_cost[i - k];
            if (i >= k - 1 && sum <= ans)
                ans = sum;
        }

        cout << ans << '\n';
    }

    void clean(void) {}
};

int main(void)
{
    cin.sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    return (new Abreto())->solve();
}
