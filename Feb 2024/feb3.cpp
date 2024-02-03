#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            int maxi = INT_MIN;
            for (int j = 1; j <= min(i, k); ++j) {
                maxi = max(maxi, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + maxi * j);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    int result = solution.maxSumAfterPartitioning(arr, k);

    cout << "Maximum sum after partitioning: " << result << endl;

    return 0;
}
