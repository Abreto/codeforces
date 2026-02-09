#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200010;

typedef long long int ll;
ll a[MAXN];

void process_case() {
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;
    ll S_all = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S_all += a[i] / x;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur = a[i] + (S_all - (a[i] / x)) * y;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t = 0;
    cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}
