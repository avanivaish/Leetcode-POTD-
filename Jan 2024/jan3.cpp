#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        for (string s : bank) {
            int count = 0;
            for (char c : s) {
                if (c == '1') count++;
            }
            if (count != 0) {
                ans += (prev * count);
                prev = count;
            }
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<string> newBank = {"011001", "000000", "010100", "001000"};
    int newResult = solution.numberOfBeams(newBank);

    cout << "Total number of beams (new test case): " << newResult << endl;

    return 0;
}
