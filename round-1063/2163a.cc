#include <iostream>
#include <algorithm>

using namespace std;

void process(void)
{
    int n = 0;
    int a[128] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    bool ok = true;
    for (int i = 1; i < n - 1; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while (t--)
        process();
    return 0;
}
