/** Codeforces Round 1107 (Div. 3) - Problem B. Good times Good times  */
#include <iomanip>
#include <iostream>

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
    int x = 0;
    cin >> x;
    cout << '1';
    while (x >= 10) {
      cout << '0';
      x /= 10;
    }
    cout << '1' << '\n';
  }
}

int main(void) {
  io_init();
  solve();
  return 0;
}
