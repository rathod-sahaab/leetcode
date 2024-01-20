#include <bits/stdc++.h>
using namespace std;

vector<int> get_topology(string parens) {
  vector<int> topology;
  topology.reserve(parens.length());

  int count = 0;

  for (const char &c : parens) {
    if (c == '(') {
      count++;
    } else {
      count--;
    }
    topology.push_back(count);
  }

  return topology;
}

void solve() {
  string parens;
  cin >> parens;

  const auto topology = get_topology(parens);

  for (const auto &elem : topology) {
    cout << elem << " ";
  }
  std::cout << "\n";
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
