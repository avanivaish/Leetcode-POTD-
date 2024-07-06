#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time / (n - 1);
        int ans = 0;
        if (round % 2 == 0) {
            ans = (1 + time % (n - 1));
        } else {
            ans = (n - time % (n - 1));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5; // Number of people
    int time = 10; // Time elapsed
    
    int result = solution.passThePillow(n, time);
    cout << "The person holding the pillow at time " << time << " is: " << result << endl;
    
    return 0;
}
