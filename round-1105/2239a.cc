#include <iomanip>
#include <iostream>

using namespace std;

void io_init(void) {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
}

int max_length(int n, int k) {
  int l = 0, a = 1;
  int r = n / k;
  while ((a << 1) - 1 <= r) {
    a <<= 1;
    l++;
  }
  return l;
}

void solve(void) {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0, k = 0;
    cin >> n >> k;

    int l = max_length(n, k);
    int rest = n - k * ((1 << l) - 1);
    int ans = rest / (1 << l) + k * l;

    cout << ans << '\n';
  }
}

int main(void) {
  io_init();
  solve();
  return 0;
}
