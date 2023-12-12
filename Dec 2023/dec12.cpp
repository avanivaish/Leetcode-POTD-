#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        // Calculate the maximum product
        int result = (max1 - 1) * (max2 - 1);

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create a vector of integers
    vector<int> nums = {3, 4, 5, 2};

    // Call the maxProduct function and print the result
    int maxProductResult = solution.maxProduct(nums);

    cout << "Maximum Product: " << maxProductResult << endl;

    return 0;
}
