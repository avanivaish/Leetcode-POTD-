#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; // store durations of free gaps

        // First free gap from time 0 to first event start
        freeArray.push_back(startTime[0]);

        // Free gaps between events
        for (int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i - 1]);
        }

        // Last free gap from last event end to end of day
        freeArray.push_back(eventTime - endTime.back());

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);

        // Compute max free time to the right of each index
        for (int i = n - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freeArray[i + 1]);
        }

        // Compute max free time to the left of each index
        for (int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i - 1], freeArray[i - 1]);
        }

        int result = 0;

        // Iterate to find max possible free time if we move one event
        for (int i = 1; i < n; i++) {
            int currEventTime = endTime[i - 1] - startTime[i - 1]; // duration of (i-1)th event

            // Case 1: Move current event completely out (if enough space is available)
            if (currEventTime <= max(maxLeftFree[i - 1], maxRightFree[i])) {
                result = max(result, freeArray[i - 1] + currEventTime + freeArray[i]);
            }

            // Case 2: Shift only left or right (not removing event)
            result = max(result, freeArray[i - 1] + freeArray[i]);
        }

        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    int eventTime = 24; // Assume the day ends at 24
    vector<int> startTime = {2, 8, 14};
    vector<int> endTime = {5, 10, 18};

    int result = sol.maxFreeTime(eventTime, startTime, endTime);
    cout << "Maximum possible free time: " << result << endl;

    return 0;
}
