#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count = 0;

        // Iterate through the string
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                count += 1;
            }
        }

        // If the first and last characters are not alternating, increment count
        if (s[0] == s[n - 1]) {
            count += 1;
        }

        return (count + 1) / 2;
    }
};

// Example usage:
int main() {
    Solution solution;

    string s1 = "0100";
    int result1 = solution.minOperations(s1);
    cout << "Minimum operations to make \"" << s1 << "\" balanced: " << result1 << endl;
    // Output: 1

    string s2 = "10";
    int result2 = solution.minOperations(s2);
    cout << "Minimum operations to make \"" << s2 << "\" balanced: " << result2 << endl;
    // Output: 0

    string s3 = "1111";
    int result3 = solution.minOperations(s3);
    cout << "Minimum operations to make \"" << s3 << "\" balanced: " << result3 << endl;
    // Output: 2


    string s4 = "110010";
    int result4 = solution.minOperations(s4);
    cout << "Minimum operations to make \"" << s4 << "\" balanced: " << result4 << endl;
    // Output: 2

    return 0;
}
