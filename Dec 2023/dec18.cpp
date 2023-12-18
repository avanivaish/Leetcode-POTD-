#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= min1){
                min2 = min1;
                min1 = nums[i];
            } else if(nums[i] < min2){
                min2 = nums[i];
            }
            
            if(nums[i] >= max1){
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2){
                max2 = nums[i];
            }
        }
        
        return ((max2 * max1) - (min1 * min2));
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {4, 2, 5, 9, 7, 4, 8};
    int result = solution.maxProductDifference(nums);

    cout << "Result: " << result << endl;

    return 0;
}
