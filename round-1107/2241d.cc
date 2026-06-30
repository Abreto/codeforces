/** Codeforces Round 1107 (Div. 3) - Problem D. An Alternative Way */
#include <iomanip>
#include <iostream>

using namespace std;

void io_init(void) {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
}

namespace workaround {

using i64 = long long;

const size_t MAXN = 200000;
int n;
i64 a[MAXN + 10], b[MAXN + 10];

void process_one_case() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = n - 1; i > 0; i--) {
    if (a[i] > b[i]) {
      a[i - 1] += a[i] - b[i];
    }
  }

  bool ans = a[0] <= b[0];
  cout << (ans ? "YES" : "NO") << '\n';
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
