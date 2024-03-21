/* Codeforces Round #628 (Div. 2). Problem B. */
#include <bits/stdc++.h>

using namespace std;

namespace abreto {

const int maxn = 100100;

int n;
int a[maxn];

int answer(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    return (unique(a, a + n) - a);
}

void main(void)
{
    int t;
    cin >> t;
    while (t--) {
        cout << answer() << '\n';
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
