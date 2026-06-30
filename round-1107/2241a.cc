/** Codeforces Round 1107 (Div. 3) - Problem A. Divide and Conquer */
#include <iostream>
#include <iomanip>

using namespace std;

void io_init(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(16);
}

void solve(void) {
    int t = 0;
    cin >> t;
    while (t--) {
        int x = 0, y = 0;
        cin >> x >> y;
        int yes = (0 == x % y);
        cout << (yes ? "YES" : "NO") << '\n';
    }
}

int main(void) {
    io_init();
    solve();
    return 0;
}
