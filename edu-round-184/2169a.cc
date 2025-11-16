#include <iostream>
#include <algorithm>

using namespace std;

const size_t MAXN = 300000;
int v[MAXN];

void process_case(void)
{
    int n = 0, a = 0;
    cin >> n >> a;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v, v + n);

    auto score = [&](int b)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            int dis_alice = abs(v[i] - a), dis_bob = abs(v[i] - b);
            s += (dis_alice > dis_bob);
        }
        return s;
    };

    int points1 = score(a + 1), points2 = score(a - 1);
    int b = (points1 > points2) ? (a + 1) : (a - 1);

    cout << b << "\n";
}

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--)
        process_case();
    return 0;
}
