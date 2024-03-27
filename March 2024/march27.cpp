#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int ans = 0;
        int prod = 1;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            prod *= nums[r];
            while (prod >= k)
                prod /= nums[l++];
            ans += r - l + 1;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 5, 2, 6}; // Example input nums
    int k = 100; // Example value of k

    int result = solution.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}
