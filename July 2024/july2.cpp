#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            auto it = mp.find(nums2[i]);
            if(it != mp.end() && it->second > 0) {
                ans.push_back(nums2[i]);
                it->second--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = solution.intersect(nums1, nums2);
    
    cout << "Intersection of nums1 and nums2: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
