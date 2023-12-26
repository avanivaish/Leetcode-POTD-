#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    const int n = s.length();
    // dp[i] := the number of ways to decode s[i..n)
    vector<int> dp(n + 1);
    dp[n] = 1;  // ""
    dp[n - 1] = isValid(s[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      if (isValid(s[i]))
        dp[i] += dp[i + 1];
      if (isValid(s[i], s[i + 1]))
        dp[i] += dp[i + 2];
    }

    return dp[0];
  }

 private:
  bool isValid(char c) {
    return c != '0';
  }

  bool isValid(char c1, char c2) {
    return c1 == '1' || c1 == '2' && c2 < '7';
  }
};

#include <iostream>

int main() {
  // Example usage
  Solution solution;
  string input = "226";
  int result = solution.numDecodings(input);

  cout << "Number of ways to decode \"" << input << "\": " << result << endl;

  return 0;
}
