#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int sum = k * (2 * 28 + (k - 1) * 7) / 2;
        for (int days = 0; days < n % 7; days++) {
            sum += (k + 1) + days;
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // Example 1
    int n1 = 4;
    cout << "Example 1 - Input: " << n1 << ", Output: " << solution.totalMoney(n1) << endl;

    // Example 2
    int n2 = 10;
    cout << "Example 2 - Input: " << n2 << ", Output: " << solution.totalMoney(n2) << endl;

    // Example 3
    int n3 = 20;
    cout << "Example 3 - Input: " << n3 << ", Output: " << solution.totalMoney(n3) << endl;

    return 0;
}
