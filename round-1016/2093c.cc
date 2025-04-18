/** Codeforces Round 1016 (Div. 3). Problem C. Simple Repetition.  */
#include <iostream>
#include <iomanip>

namespace cf1016c
{
    using namespace std;
    using ll = long long;

    class IoInit
    {
    public:
        IoInit()
        {
            cin.sync_with_stdio(false);
            cin.tie(0);
            cout << fixed << setprecision(12);
        }
    } _ioInit;

    bool is_prime(int x)
    {
        if (1 >= x)
            return false;
        if (2 == x || 3 == x)
            return true;
        for (ll i = 2; i * i <= x; i++)
        {
            if (0 == x % i)
                return false;
        }
        return true;
    }

    void solve(void)
    {
        int x = 0, k = 0;
        cin >> x >> k;
        if (k > 1)
        {
            if (x > 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << ((2 == k) ? "YES" : "NO") << endl;
            }
        }
        else
        {
            cout << (is_prime(x) ? "YES" : "NO") << endl;
        }
    }
}

int main(void)
{
    using namespace cf1016c;
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
