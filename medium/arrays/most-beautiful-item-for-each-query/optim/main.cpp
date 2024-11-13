#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct IndexElement {
  int price;
  int beauty;
};

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    // sort items
    sort(items.begin(), items.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });

    vector<IndexElement> distilled; // best beauty for a price

    for (const auto &item : items) {
      const auto curr = IndexElement{item[0], item[1]};

      if (distilled.size() == 0) {
        distilled.push_back(curr);
      }

      if (distilled.back().beauty < curr.beauty) {
        if (distilled.back().price == curr.price) {
          distilled.back().beauty = curr.beauty;
        } else {
          distilled.push_back(curr);
        }
      }
    }

    vector<int> result;
    result.reserve(queries.size());

    for (const int query : queries) {
      const auto affordable = upper_bound(
          distilled.cbegin(), distilled.cend(), query,
          [](const int q, const IndexElement &idx) { return idx.price > q; });

      // Move one step back if we're not at the beginning of the array
      if (affordable != distilled.cbegin()) {
        result.push_back((affordable - 1)->beauty);
      } else {
        result.push_back(0);
      }
    }

    return result;
  }
};

int main() {
  vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
  vector<int> queries = {1, 2, 3, 4, 5, 6};

  Solution s;

  const auto result = s.maximumBeauty(items, queries);

  for (const auto &el : result) {
    cout << el << ',';
  }
  cout << endl;
}
