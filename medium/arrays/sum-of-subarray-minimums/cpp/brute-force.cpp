#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    constexpr const int MOD = 1e9 + 7;
    // pick sub arrays
    int sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j <= arr.size(); ++j) {
        sum =
            (sum + *min_element(arr.begin() + i, arr.begin() + j) % MOD) % MOD;
      }
    }

    return sum;
  }
};
