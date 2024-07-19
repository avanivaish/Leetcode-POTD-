#include <iostream>
#include <vector>
#include <algorithm> // For std::ranges::min_element
using namespace std;

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    for (const vector<int>& row : matrix) {
      const int minIndex = distance(row.begin(), ranges::min_element(row));
      if (row[minIndex] == maxNumOfColumn(matrix, minIndex))
        return {row[minIndex]};
    }
    return {};
  }

 private:
  int maxNumOfColumn(const vector<vector<int>>& matrix, int j) {
    int res = 0;
    for (int i = 0; i < matrix.size(); ++i)
      res = max(res, matrix[i][j]);
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix = {
    {3, 7, 8},
    {9, 11, 13},
    {15, 16, 17}
  };

  vector<int> result = sol.luckyNumbers(matrix);

  cout << "Lucky Numbers: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
