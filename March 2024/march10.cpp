#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> set{nums1.begin(), nums1.end()};

    for (const int num : nums2)
      if (set.erase(num))
        ans.push_back(num);

    return ans;
  }
};

int main() {
    // Example usage
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);
    
    cout << "Intersection of nums1 and nums2: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;
    
    return 0;
}
