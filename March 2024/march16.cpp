#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i] ? 1 : -1;
            auto it = prefixToIndex.find(prefix);
            if (it != prefixToIndex.cend()) {
                ans = max(ans, i - it->second);
            } else {
                prefixToIndex[prefix] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 1, 0, 0, 1};
    cout << "Maximum length of contiguous subarray with equal number of 0s and 1s: " << solution.findMaxLength(nums) << endl;
    return 0;
}
