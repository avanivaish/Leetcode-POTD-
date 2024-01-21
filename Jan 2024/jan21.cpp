#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        // dp[i] := the maximum money of robbing nums[0..i]
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i)
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);

        return dp.back();
    }
};

int main() {
    using namespace std; // Add this line to use the std namespace

    Solution solution;

    // Example usage:
    vector<int> nums = {2, 7, 9, 3, 1};
    int result = solution.rob(nums);

    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
