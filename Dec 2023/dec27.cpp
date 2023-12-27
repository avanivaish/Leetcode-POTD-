#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& cost) {
        int res = 0, max_cost = 0, sum_cost = 0, n = colors.size();
        for(int i = 0; i < n; ++i) {
            if(i > 0 && colors[i] != colors[i - 1]) {
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        res += sum_cost - max_cost;
        return res;
    }
};

int main() {
    Solution solution;

    // Example usage:
    string colors = "abaac";
    vector<int> cost = {1, 2, 3, 1, 5};

    int result = solution.minCost(colors, cost);

    cout << "Minimum cost: " << result << endl;

    return 0;
}
