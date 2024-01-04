#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int el : nums) {
            ++mp[el];
        }
        int ans = 0;
        for (const auto& entry : mp) {
            int cnt = entry.second;
            int el = entry.first;

            if (cnt == 1) return -1;
            ans += cnt / 3 + (cnt % 3 > 0);
        }
        return ans;
    }
};

int main() {
    // Example 1
    vector<int> nums1 = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    Solution sol1;
    cout << "Example 1: " << sol1.minOperations(nums1) << endl;

    // Example 2
    vector<int> nums2 = {2, 1, 2, 2, 3, 3};
    Solution sol2;
    cout << "Example 2: " << sol2.minOperations(nums2) << endl;

    return 0;
}
