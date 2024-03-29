#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        constexpr int kMod = 1'000'000'007;
        // dp[i][j] := the number of permutations of numbers 1..i with j inverse pairs
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        // If there's no inverse pair, the permutation is unique "123..i".
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % kMod;
                if (j - i >= 0)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + kMod) % kMod;
            }

        return dp[n][k];
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example values for n and k
    int n = 3;
    int k = 1;

    int result = solution.kInversePairs(n, k);

    // Output the result
    cout << "Number of permutations with " << k << " inverse pairs for " << n << " elements: " << result << endl;

    return 0;
}
