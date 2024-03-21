/* Codeforces - Hello 2020, Problem A. */
#include <bits/stdc++.h>

using namespace std;

#define COUT_PRECISION 10

namespace abreto {

const int MAXN = 32, MAXL = 16;

int n, m;
int p;
char s[MAXN][MAXL], t[MAXN][MAXL];

void answer_queries(void) {
    int q, y;
    cin >> q;
    while (q--) {
        cin >> y;
        --y;
        cout << s[y % n] << t[y % m] << '\n';
    }
}

void main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> t[i];
    p = n * m;
    answer_queries();
}

}

int main(void) {
    cin.sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(COUT_PRECISION);
    abreto::main();
    return 0;
}
