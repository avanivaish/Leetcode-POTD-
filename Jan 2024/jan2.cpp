#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;

        for (auto el : nums) {
            freq[el]++;
            if (ans.size() < freq[el]) {
                ans.push_back({});
            }
            ans[freq[el] - 1].push_back(el);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 1, 3, 2, 4, 5, 4, 2};
    vector<vector<int>> result = solution.findMatrix(nums);

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
