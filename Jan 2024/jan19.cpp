#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0; i<m; i++) dp[0][i]=matrix[0][i];
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int minValue = INT_MAX;
                if(i-1>=0) minValue = min(minValue,dp[i-1][j]);
                if(i-1>=0 && j-1>=0) minValue = min(minValue,dp[i-1][j-1]);
                if(i-1>=0 && j+1<m) minValue = min(minValue,dp[i-1][j+1]);

                dp[i][j]=minValue+matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<m; j++) ans = min(ans,dp[n-1][j]);
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    
    int result = solution.minFallingPathSum(matrix);
    
    cout << "Minimum Falling Path Sum: " << result << endl;
    
    return 0;
}
