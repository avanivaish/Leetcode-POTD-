#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> mem(maxMove + 1,
                                    vector<vector<int>>(m, vector<int>(n, -1)));
    return findPaths(m, n, maxMove, startRow, startColumn, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of paths to move the ball at (i, j) out-of-bounds with k moves.
  int findPaths(int m, int n, int k, int i, int j,
                vector<vector<vector<int>>>& mem) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (mem[k][i][j] != -1)
      return mem[k][i][j];
    return mem[k][i][j] = (findPaths(m, n, k - 1, i + 1, j, mem) * 1LL +
                           findPaths(m, n, k - 1, i - 1, j, mem) +
                           findPaths(m, n, k - 1, i, j + 1, mem) +
                           findPaths(m, n, k - 1, i, j - 1, mem)) %
                          kMod;
  }
};

int main() {
  Solution solution;
  int m = 2;
  int n = 2;
  int maxMove = 2;
  int startRow = 0;
  int startColumn = 0;

  int result = solution.findPaths(m, n, maxMove, startRow, startColumn);

  cout << "Number of paths: " << result << endl;

  return 0;
}
