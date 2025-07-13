#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Sort both arrays so we can use a greedy two-pointer approach
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0; // pointer for players
        int j = 0; // pointer for trainers
        int count = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // Match found
                count++;
                i++;
                j++;
            } else {
                // Trainer too weak, try next trainer
                j++;
            }
        }

        return count;
    }
};

int main() {
    // Example test case 1
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};

    Solution sol;
    int result = sol.matchPlayersAndTrainers(players, trainers);
    cout << "Maximum matches: " << result << endl;

    // Example test case 2
    players = {1, 1, 1};
    trainers = {10};
    result = sol.matchPlayersAndTrainers(players, trainers);
    cout << "Maximum matches: " << result << endl;

    return 0;
}
