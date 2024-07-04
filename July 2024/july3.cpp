#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDiff(vector<int>& nums) {
        int n = nums.size();
        return min({nums[n-1]-nums[3], nums[n-2]-nums[2], nums[n-3]-nums[1], nums[n-4]-nums[0]});
    }
    
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        return minDiff(nums);
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums = {5, 3, 2, 4, 1, 6};
    int result = sol.minDifference(nums);

    // Print the result
    cout << "The minimum difference is: " << result << endl;

    return 0;
}
