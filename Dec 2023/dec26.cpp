#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int diceIndex, int remTarget, int n, int k) {
        if (diceIndex == n) return (remTarget == 0);
        if (remTarget < 0) return 0;

        if (dp[diceIndex][remTarget] != -1) {
            return dp[diceIndex][remTarget];
        }

        int ans = 0;
        for (int face = 1; face <= k; face++) {
            ans = (ans + solve(diceIndex + 1, remTarget - face, n, k)) % mod;
        }

        return dp[diceIndex][remTarget] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<int>(target + 1, -1));
        return solve(0, target, n, k);
    }
};

#include <iostream>

int main() {
    // Example usage
    Solution solution;

    int n = 2;    // Number of dice
    int k = 6;    // Number of faces on each die
    int target = 7;  // Target sum

    int result = solution.numRollsToTarget(n, k, target);

    cout << "Number of ways to roll the dice to get the target sum: " << result << endl;

    return 0;
}
