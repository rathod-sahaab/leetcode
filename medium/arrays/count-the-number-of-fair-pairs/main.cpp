#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());

    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      const auto curr = nums[i];

      const auto low = lower - curr;
      const auto high = upper - curr;

      const int low_idx =
          lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();

      const int up_idx =
          upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();

      sum += up_idx - low_idx;
    }

    return sum;
  }
};

int main() {
  vector<int> nums = {0, 1, 7, 4, 4, 5};

  Solution s;

  const auto result = s.countFairPairs(nums, 3, 6);

  cout << result << endl;
}
