#include <iostream>
#include<bits/stdc++.h>
#include <vector>

#define ll long long int

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<ll, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll diff = (ll) nums[i] - nums[j];
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = solution.numberOfArithmeticSlices(nums);

    cout << "Number of arithmetic slices: " << result << endl;

    return 0;
}
