#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int val = min(rowSum[i], colSum[j]);
                matrix[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        
        return matrix;
    }
};

int main() {
    Solution sol;
    
    vector<int> rowSum1 = {3, 8};
    vector<int> colSum1 = {4, 7};
    vector<vector<int>> result1 = sol.restoreMatrix(rowSum1, colSum1);
    
    cout << "Resulting matrix for rowSum = {3, 8} and colSum = {4, 7}:\n";
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> rowSum2 = {5, 7, 10};
    vector<int> colSum2 = {8, 6, 8};
    vector<vector<int>> result2 = sol.restoreMatrix(rowSum2, colSum2);
    
    cout << "\nResulting matrix for rowSum = {5, 7, 10} and colSum = {8, 6, 8}:\n";
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
