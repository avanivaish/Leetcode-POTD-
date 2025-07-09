#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int left, right, time = 0;
        int n = startTime.size();
        int boundryLength = 0;
        int freeTime = 0;

        for (int i = 0; i < n; i++) {
            time += endTime[i] - startTime[i];
            left = i <= k - 1 ? 0 : endTime[i - k];
            right = i == n - 1 ? eventTime : startTime[i + 1];
            boundryLength = (right - left);
            freeTime = max(freeTime, boundryLength - time);
            if (i >= k - 1) {
                time -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return freeTime;
    }
};

int main() {
    Solution sol;

    // Sample input
    int eventTime = 30;
    int k = 2;
    vector<int> startTime = {1, 10, 15};
    vector<int> endTime = {5, 12, 20};

    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum Free Time: " << result << endl;

    return 0;
}
