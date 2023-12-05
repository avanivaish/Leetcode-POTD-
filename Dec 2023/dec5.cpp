#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n>1){
            if(n%2==0){
                ans += n/2;
                n = n/2;
            }else{
                ans += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return ans;
        //return n - 1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 7;
    int result1 = solution.numberOfMatches(n1);
    cout << "Input: " << n1 << ", Output: " << result1 << endl;

    // Test case 2
    int n2 = 14;
    int result2 = solution.numberOfMatches(n2);
    cout << "Input: " << n2 << ", Output: " << result2 << endl;

    return 0;
}
