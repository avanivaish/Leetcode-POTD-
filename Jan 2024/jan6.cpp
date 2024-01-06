#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& start, int n, int id){
        if(id == n) return 0;
        if(dp[id] != -1) return dp[id];
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[id][1]) - start.begin();
        int maxProfit = max(findMaxProfit(jobs, start, n, id+1), jobs[id][2] + findMaxProfit(jobs, start, n, nextIndex));
        return dp[id] = maxProfit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < profit.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(int i = 0; i < profit.size(); i++){
            startTime[i] = jobs[i][0];
        }
        return findMaxProfit(jobs, startTime, profit.size(), 0);
    }

private:
    int dp[50005];
};

int main() {
    Solution solution;

    // Example input data
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    // Call the jobScheduling function
    int result = solution.jobScheduling(startTime, endTime, profit);

    // Display the result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
