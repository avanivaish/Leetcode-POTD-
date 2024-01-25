#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.length();
    const int n = text2.length();
    // dp[i][j] := the length of LCS(text1[0..i), text2[0..j))
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j + 1] = text1[i] == text2[j]
                               ? 1 + dp[i][j]
                               : max(dp[i][j + 1], dp[i + 1][j]);

    return dp[m][n];
  }
};

int main() {
    // Example usage
    Solution solution;

    // Test case 1
    string text1 = "abcde";
    string text2 = "ace";
    int result1 = solution.longestCommonSubsequence(text1, text2);
    cout << "LCS for \"" << text1 << "\" and \"" << text2 << "\" is: " << result1 << endl;

    // Test case 2
    string text3 = "abc";
    string text4 = "def";
    int result2 = solution.longestCommonSubsequence(text3, text4);
    cout << "LCS for \"" << text3 << "\" and \"" << text4 << "\" is: " << result2 << endl;

    // Add more test cases as needed

    return 0;
}
