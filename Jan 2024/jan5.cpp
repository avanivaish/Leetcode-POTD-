#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                int index = distance(temp.begin(), it);
                temp[index] = nums[i];
            }
        }

        return len;
    }
};

int main() {
    // Example usage:
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    Solution solution;
    int result = solution.lengthOfLIS(nums);

    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
