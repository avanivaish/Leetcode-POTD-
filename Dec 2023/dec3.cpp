#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 1; i < n; i++) {
            ans += std::max(std::abs(points[i][0] - points[i - 1][0]),
                            std::abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
};

int main() {

    // Example usage
    Solution solution;
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    int result = solution.minTimeToVisitAllPoints(points);

    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}
