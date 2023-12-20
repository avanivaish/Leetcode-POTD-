#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int x_len = img.size();
        int y_len = (x_len > 0) ? img[0].size() : 0;
        vector<vector<int>> res = img;

        for (int x = 0; x < x_len; ++x) {
            for (int y = 0; y < y_len; ++y) {
                vector<int> neighbors;
                for (int _x : {x-1, x, x+1}) {
                    for (int _y : {y-1, y, y+1}) {
                        if (_x >= 0 && _x < x_len && _y >= 0 && _y < y_len) {
                            neighbors.push_back(img[_x][_y]);
                        }
                    }
                }
                res[x][y] = accumulate(neighbors.begin(), neighbors.end(), 0) / neighbors.size();
            }
        }

        return res;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<vector<int>> input = {{1, 1, 1},
                                 {1, 0, 1},
                                 {1, 1, 1}};

    vector<vector<int>> result = solution.imageSmoother(input);

    // Displaying the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
