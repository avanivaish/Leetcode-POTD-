#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> winners, losers;
        unordered_map<int, int> table;

        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];

            table[winner] = table[winner]; // Winner
            table[loser] = table[loser] + 1;
        }

        for (const auto& entry : table) {
            int player = entry.first;
            int losses = entry.second;

            if (losses == 0) {
                winners.push_back(player);
            }
            if (losses == 1) {
                losers.push_back(player);
            }
        }

        // Sorting the arrays
        sort(winners.begin(), winners.end());
        sort(losers.begin(), losers.end());

        return {winners, losers};
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example input: matches
    vector<vector<int>> matches = {
        {1, 2},
        {2, 3},
        {4, 5},
        {5, 6}
        // Add more matches as needed
    };

    // Calling the findWinners method
    vector<vector<int>> result = solution.findWinners(matches);

    // Displaying the results
    cout << "Winners: ";
    for (const auto& winner : result[0]) {
        cout << winner << " ";
    }
    cout << endl;

    cout << "Losers: ";
    for (const auto& loser : result[1]) {
        cout << loser << " ";
    }
    cout << endl;

    return 0;
}
