#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
public:
  Solution();

  void rotate(vector<vector<int>> &matrix) {
    const auto SIZE = matrix.size();
    const auto L = SIZE - 1;

    if (SIZE <= 1) {
      return;
    }

    for (int c = 0; c < SIZE / 2; ++c) {
      int r = c, R = L - c;

      for (int quadruplet = 0; quadruplet < R - r; ++quadruplet) {
        pair<int, int> cord{r, r + quadruplet};

        const int j = r + quadruplet;

        // TODO: const array of length 4, incorporate cord too
        const vector<pair<int, int>> swaps{
            {L - j, r},
            {R, L - j},
            {j, R},
        };

        // TODO: std::views::adjacent
        for (const pair<int, int> &next_cord : swaps) {
          swap(matrix[cord.first][cord.second],
               matrix[next_cord.first][next_cord.second]);

          cord = next_cord;
        }
      }
    }
  }
};
