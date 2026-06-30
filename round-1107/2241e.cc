/** Codeforces Round 1107 (Div. 3) - Problem E. Fair and Square */
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void io_init(void) {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
}

namespace workaround {

using ll = int64_t;

const size_t MAXN = 200000;
const size_t ROOT = 1;

int n;
ll a[MAXN + 10];
vector<vector<int>> g;
ll ans;

ll subtree_size[MAXN + 10];

bool is_perfect_square(ll x) {
  for (ll i = 1; i * i <= x; i++) {
    if (i * i == x) {
      return true;
    }
  }
  return false;
}

void dfs(size_t u, size_t fa) {
  subtree_size[u] = 1;
  for (int v : g[u]) {
    if (subtree_size[v] == 0) {
      dfs(v, u);
      subtree_size[u] += subtree_size[v];
    }
  }

  if (is_perfect_square(a[u])) {
    ll s1 = n - subtree_size[u], s2 = 0, s3 = 0;
    for (auto &&v : g[u]) {
      if (v == fa)
        continue;
      ll c = subtree_size[v];
      s3 += s2 * c;
      s2 += s1 * c;
      s1 += c;
    }
    ans += s2 + s3;
  }
}

void process_one_case() {
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].clear();
    subtree_size[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u = 0, v = 0;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  ans = 0;
  dfs(ROOT, 0);

  cout << ans << '\n';
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
