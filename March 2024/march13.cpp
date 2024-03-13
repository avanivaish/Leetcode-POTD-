#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        // 1 + 2 + ... + x = x + ... + n
        // (1 + x) * x / 2 = (x + n) * (n - x + 1) / 2
        // x + x^2 = nx - x^2 + x + n^2 - nx + n
        // 2 * x^2 = n^2 + n
        // x = sqrt((n^2 + n) / 2)
        const int y = (n * n + n) / 2;
        const int x = sqrt(y);
        return x * x == y ? x : -1;
    }
};

int main() {
    Solution solution;
    int n=8;
    int result = solution.pivotInteger(n);
    if (result != -1) {
        cout << "The pivot integer for " << n << " is: " << result << endl;
    } else {
        cout << "No pivot integer found for " << n << endl;
    }
    return 0;
}
