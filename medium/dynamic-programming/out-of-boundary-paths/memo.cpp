#include <vector>
using namespace std;

class Solution {
  static constexpr const int MOD = 1e9 + 7;

public:
  static long long findPathsRecur(vector<vector<vector<int>>> &memo, int m,
                                  int n, int maxMove, int startRow,
                                  int startColumn) {
    if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) {
      return 1;
    }

    if (maxMove <= 0) {
      return 0;
    }

    if (memo[startRow][startColumn][maxMove] != -1) {
      return memo[startRow][startColumn][maxMove];
    }

    memo[startRow][startColumn][maxMove] =
        // up
        (findPathsRecur(memo, m, n, maxMove - 1, startRow - 1, startColumn) %
             MOD
         // down
         + findPathsRecur(memo, m, n, maxMove - 1, startRow + 1, startColumn) %
               MOD
         // left
         + findPathsRecur(memo, m, n, maxMove - 1, startRow, startColumn - 1) %
               MOD
         // right
         + findPathsRecur(memo, m, n, maxMove - 1, startRow, startColumn + 1) %
               MOD) %
        MOD;

    return memo[startRow][startColumn][maxMove];
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // create m X n X maxMove 3d vector and fill with -1s
    vector<vector<vector<int>>> memo(
        m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

    return findPathsRecur(memo, m, n, maxMove, startRow, startColumn) % MOD;
  }
};
