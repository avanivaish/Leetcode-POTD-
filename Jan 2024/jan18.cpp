
#include <iostream>
#include<vector>
using namespace std;
class Solution {
 public:
  int climbStairs(int n) {
    // dp[i] := the number of ways to climb to the i-th stair
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};
int main() {
    // Example usage of the climbStairs function
    Solution solution;

    // Replace 5 with the desired number of stairs
    int n = 5;

    int waysToClimb = solution.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << waysToClimb << endl;

    return 0;
}
