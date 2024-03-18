#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    int ans = 1;
    int arrowX = points[0][1];

    for (int i = 1; i < points.size(); ++i)
      if (points[i][0] > arrowX) {
        arrowX = points[i][1];
        ++ans;
      }

    return ans;
  }
};

int main() {
  // Example usage of Solution class
  Solution sol;
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << "Minimum arrows required: " << sol.findMinArrowShots(points) << endl;
  return 0;
}
