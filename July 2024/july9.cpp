#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long currentTime = 0;
        long long totalWaitTime = 0;

        for(int i = 0; i < n; i++) {
            int arrivalTime = customers[i][0];
            int cookTime = customers[i][1];
            
            // Update current time to the maximum of the current time and arrival time
            currentTime = max(currentTime, (long long)arrivalTime);
            // Customer starts being served at currentTime
            // Wait time is the time customer has to wait until food is ready
            totalWaitTime += currentTime + cookTime - arrivalTime;
            // Update current time to when this customer finishes being served
            currentTime += cookTime;
        }

        return (double)totalWaitTime / n;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> customers = {
        {2, 3}, {6, 3}, {7, 5}, {11, 3}, {15, 2}, {18, 1}
    };
    double result = solution.averageWaitingTime(customers);
    cout << fixed << result << endl; // Output should be in fixed-point notation
    return 0;
}
