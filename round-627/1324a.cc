/* Codeforces Round #627 (Div. 3). Problem A - Yet Another Tetris Problem. */
#include <bits/stdc++.h>

using namespace std;

namespace abreto {

bool answer(void)
{
    int n, a[128];
    bool ok = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && ((a[i] - a[i - 1]) & 1))
            ok = false;
    }
    return ok;
}

void main(void)
{
    int t;
    cin >> t;
    while (t--) cout << (answer() ? "YES" : "NO") << '\n';
}

}

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);
    abreto::main();
    return 0;
}
