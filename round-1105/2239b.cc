#include <iomanip>
#include <iostream>

using namespace std;

using ll = long long int;
const ll MOD = 998244353;

void io_init(void) {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
}

ll fast_pow(ll a, ll n, ll p) {
  ll r = 1;
  while (n) {
    if (n & 1) {
      r = (r * a) % p;
    }
    a = (a * a) % p;
    n >>= 1;
  }
  return r;
}

void solve(void) {
  int t = 0;
  cin >> t;
  while (t--) {
    ll n = 0, m = 0, r = 0, c = 0;
    cin >> n >> m >> r >> c;

    ll ans = fast_pow(2, n * m - (n - r + 1) * (m - c + 1), MOD);
    cout << ans << '\n';
  }
}

int main(void) {
  io_init();
  solve();
  return 0;
}
