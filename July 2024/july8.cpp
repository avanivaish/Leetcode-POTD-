#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            for (int j = 1; j < k; j++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

int main() {
    Solution sol;
    int n = 5; // Number of friends
    int k = 3; // Elimination step
    int winner = sol.findTheWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;
    return 0;
}
