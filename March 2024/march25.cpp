#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (const int num : nums) {
            nums[abs(num) - 1] *= -1;
            if (nums[abs(num) - 1] > 0)
                ans.push_back(abs(num));
        }

        return ans;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> duplicates = solution.findDuplicates(nums);

    cout << "Duplicates: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
