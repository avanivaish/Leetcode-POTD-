#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<int> ans;
    vector<tuple<int, int, int>> A;  // (mapped, index, num)

    for (int i = 0; i < nums.size(); ++i)
      A.emplace_back(getMapped(nums[i], mapping), i, nums[i]);

    sort(A.begin(), A.end());

    for (const auto& [_, i, num] : A)
      ans.push_back(num);

    return ans;
  }

 private:
  int getMapped(int num, const vector<int>& mapping) {
    string mapped;
    for (const char c : to_string(num))
      mapped += to_string(mapping[c - '0']);
    return stoi(mapped);
  }
};

int main() {
  Solution solution;
  vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}; // example mapping
  vector<int> nums = {990, 332, 981}; // example nums

  vector<int> sortedNums = solution.sortJumbled(mapping, nums);

  for (int num : sortedNums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
