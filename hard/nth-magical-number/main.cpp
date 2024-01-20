#include <bits/stdc++.h>
using namespace std;

int nthMagicalNumberInefficient(int n, int a, int b) {
  long long limit = min(a, b) * n;
  long long i = 1;
  for (int counter = 0; i <= limit; ++i) {
    if (i % a == 0 or i % b == 0) {
      counter++;
    }
    if (counter == n) {
      return i % (long long)(1e9 + 7);
    }
  }
  return -1;
}

void solve() {
  int n, a, b;

  cin >> n >> a >> b;
  cout << nthMagicalNumber(n, a, b) << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
