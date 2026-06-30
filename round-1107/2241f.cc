/** Codeforces Round 1107 (Div. 3) - Problem F. A Bit Odd */
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void io_init(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(16);
}

namespace workaround {

const size_t MAXN = 200000;

int n;
char s[MAXN + 10];

void process_one_case() {
    cin >> n;
    cin >> s;

    int l = 0;
    int r = n - 1;

    while (l < n && s[l] == '0') {
        ++l;
    }

    while (r >= 0 && s[r] == '1') {
        --r;
    }

    bool ans = false;

    int i = l;
    while (i <= r) {
        int j = i;
        while (j <= r && s[j] == s[i]) {
            ++j;
        }

        int len = j - i;
        if (len % 2 == 1) {
            ans = true;
            break;
        }

        i = j;
    }

    cout << (ans ? "Alice" : "Bob") << '\n';
}

} // namespace workaround

void solve(void) {
    int t = 0;
    cin >> t;
    while (t--) {
        workaround::process_one_case();
    }
}

int main(void) {
    io_init();
    solve();
    return 0;
}
