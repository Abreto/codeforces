/* Codeforces Round #627 (Div. 3). Problem B - Yet Another Palindrome Problem. */
#include <bits/stdc++.h>

using namespace std;

namespace abreto {

const int maxn = 5050;

int appearance[maxn];

bool ans(void)
{
    int n, ai;
    bool ok = false;
    cin >> n;
    memset(appearance, 0, sizeof(appearance));
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        if (!appearance[ai]) {
            appearance[ai] = i;
            continue;
        }
        if ((i - appearance[ai]) > 1) {
            ok = true;
        }
    }
    return ok;
}

void main(void)
{
    int t;
    cin >> t;
    while (t--) cout << (ans() ? "YES" : "NO") << '\n';
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
