#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example input: vector of points
    vector<vector<int>> points = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};

    // Call the maxWidthOfVerticalArea function and print the result
    int result = solution.maxWidthOfVerticalArea(points);
    cout << "Max Width of Vertical Area: " << result << endl;

    return 0;
}
