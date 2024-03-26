#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    const int n = nums.size();

    // Correct slot:
    // nums[i] = i + 1
    // nums[i] - 1 = i
    // nums[nums[i] - 1] = nums[i]
    for (int i = 0; i < n; ++i)
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < n; ++i)
      if (nums[i] != i + 1)
        return i + 1;

    return n + 1;
  }
};

int main() {
  // Example usage:
  Solution solution;
  vector<int> nums = {3, 4, -1, 1};
  cout << "First missing positive: " << solution.firstMissingPositive(nums) << endl;

  return 0;
}
