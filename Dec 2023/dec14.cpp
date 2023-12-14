#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize counts for ones and zeros in each row and column
        vector<int> ones_row(m, 0);
        vector<int> ones_col(n, 0);
        vector<int> zeroes_row(m, 0);
        vector<int> zeroes_col(n, 0);

        // Calculate counts for ones and zeros in each row and column
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    ones_row[i] += 1;
                    ones_col[j] += 1;
                } else {
                    zeroes_row[i] += 1;
                    zeroes_col[j] += 1;
                }
            }
        }

        // Initialize the result matrix
        vector<vector<int>> result(m, vector<int>(n, 0));

        // Populate the result matrix using the calculated counts
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                result[i][j] = ones_row[i] + ones_col[j] - zeroes_row[i] - zeroes_col[j];
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    Solution solution;
    vector<vector<int>> result = solution.onesMinusZeros(grid);

    cout << "Result:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
