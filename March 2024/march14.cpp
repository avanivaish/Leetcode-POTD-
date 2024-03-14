#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int prefix = 0;
        // {prefix: number of occurrence}
        unordered_map<int, int> count{{0, 1}};

        for (const int num : nums) {
            prefix += num;
            auto it = count.find(prefix - goal);
            if (it != count.end())
                ans += it->second;
            ++count[prefix];
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Number of subarrays with sum " << goal << ": " << solution.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
