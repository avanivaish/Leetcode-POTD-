#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else{
                return nums1[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {0, 5, 6, 7, 8};
    
    int commonElement = solution.getCommon(nums1, nums2);
    
    if(commonElement != -1)
        cout << "Common element: " << commonElement << endl;
    else
        cout << "No common element found." << endl;
    
    return 0;
}
