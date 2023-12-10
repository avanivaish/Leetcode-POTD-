#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<vector<int>> inputMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> transposedMatrix = solution.transpose(inputMatrix);

    // Display the original matrix
    cout << "Original Matrix:" << endl;
    for (const auto& row : inputMatrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Display the transposed matrix
    cout << "\nTransposed Matrix:" << endl;
    for (const auto& row : transposedMatrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
