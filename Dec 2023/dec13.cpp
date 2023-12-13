#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j]) {
                    ++rowCount[i];
                    ++colCount[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] && rowCount[i] == 1 && colCount[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example usage
    vector<vector<int>> matrix = {{1, 0, 0},
                                  {0, 0, 1},
                                  {1, 0, 0}};

    Solution solution;
    int result = solution.numSpecial(matrix);
    cout << "Number of special elements: " << result << endl;

    return 0;
}
