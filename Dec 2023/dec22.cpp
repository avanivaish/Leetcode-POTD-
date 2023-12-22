#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zero = 0, one = 0, n = s.size(), ans = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i]=='1') one++;
            else zero++;

            ans = max(zero-one, ans);
        }
        if(s[n-1]=='1') one++;
        return ans+one;
    }
};

int main() {
    // Example usage:
    Solution solution;
    string input = "011101";
    int result = solution.maxScore(input);
    
    cout << "Max Score: " << result << endl;

    return 0;
}
