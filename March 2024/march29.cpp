#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element
#include <numeric>   // for std::accumulate

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    const int maxNum = *max_element(nums.begin(), nums.end());
    long long ans = 0;
    int count = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (nums[r] == maxNum)
        ++count;
      // Keep the window to include k - 1 times of the maximum number.
      while (count == k)
        if (nums[l++] == maxNum)
          --count;
      // If l > 0, nums[l..r] has k - 1 times of the maximum number. For any
      // subarray nums[i..r], where i < l, it will have at least k times of the
      // maximum number, since nums[l - 1] equals the maximum number.
      ans += l;
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 3;
  cout << sol.countSubarrays(nums, k) << endl;
  return 0;
}
