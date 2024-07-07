#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return (numBottles + (numBottles-1)/(numExchange-1));
    }
};

int main() {
    Solution sol;

    int numBottles = 9;      // Example input
    int numExchange = 3;     // Example input

    int result = sol.numWaterBottles(numBottles, numExchange);
    cout << "Maximum number of water bottles: " << result << endl;

    // Test with additional inputs
    int numBottles2 = 15;
    int numExchange2 = 4;
    int result2 = sol.numWaterBottles(numBottles2, numExchange2);
    cout << "Maximum number of water bottles: " << result2 << endl;

    return 0;
}
