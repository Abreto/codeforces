/** Codeforces Round 1107 (Div. 3) - Problem C. RemovevomeR */
#include <iomanip>
#include <iostream>

using namespace std;

void io_init(void) {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
}

const size_t MAXN = 100;

void process_one_case(void) {
  int n = 0;
  char s[MAXN + 10] = {0};
  cin >> n >> s;

  int cnt_flip = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      cnt_flip++;
    }
  }

  int ans = (cnt_flip == 1) ? 2 : 1;
  cout << ans << '\n';
}

void solve(void) {
  int t = 0;
  cin >> t;
  while (t--) {
    process_one_case();
  }
}

int main(void) {
  io_init();
  solve();
  return 0;
}
