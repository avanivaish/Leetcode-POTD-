#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main() {
  Solution solution;
  
  // Example usage
  vector<int> nums = {1, 3, 4, 2, 2}; // Example input
  int duplicate = solution.findDuplicate(nums);
  
  cout << "The duplicate number is: " << duplicate << endl;

  return 0;
}
