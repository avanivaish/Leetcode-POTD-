#include <iostream>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // Iterate from the end of the string
        for (int i = num.length() - 1; i >= 0; --i) {
            // Check if the current digit is odd
            if ((num[i] - '0') % 2 == 1) {
                // Return the substring from the beginning of the string to the current index
                return num.substr(0, i + 1);
            }
        }

        // If no odd digit is found, return an empty string
        return "";
    }
};

int main() {
    Solution solution;

    // Example usage:
    string input = "1632";
    string result = solution.largestOddNumber(input);

    // Display the result
    cout << "Largest Odd Number: " << result << endl;

    return 0;
}
