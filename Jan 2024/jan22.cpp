#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int duplicate;

    for (const int num : nums)
      if (nums[abs(num) - 1] < 0)
        duplicate = abs(num);
      else
        nums[abs(num) - 1] *= -1;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > 0)
        return {duplicate, i + 1};

    throw runtime_error("Invalid input");
  }
};

int main() {
  // Example usage:
  Solution solution;
  vector<int> input = {1, 2, 2, 4}; // Replace this with your input

  try {
    vector<int> result = solution.findErrorNums(input);

    cout << "Duplicate: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
