#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        int prd = 1;
        for(int i=0; i<n; i++){
            prd *= nums[i];
            output.push_back(prd);
        }
        prd = 1;
        for(int i = n-1; i>0; --i){
            output[i]=output[i-1]*prd;
            prd *=nums[i];
        }
        output[0]=prd;
        return output;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << "Result: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
