#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4;
        for (int i = 0; i < n - target; i++) {
            if (arr[i] == arr[i + target]) {
                return arr[i];
            }
        }
        return -1;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Create a vector with some integers
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};

    // Call the findSpecialInteger function and print the result
    int result = solution.findSpecialInteger(arr);
    if (result != -1) {
        cout << "Special Integer: " << result << endl;
    } else {
        cout << "No special integer found." << endl;
    }

    return 0;
}
