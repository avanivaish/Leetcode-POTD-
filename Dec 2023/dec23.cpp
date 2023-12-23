#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> s;
        s.insert("0,0");

        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else x--;

            string cord = to_string(x) + "," + to_string(y);
            if (s.find(cord) != s.end()) return true;
            s.insert(cord);
        }

        return false;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    string examplePath = "NESE"; // Replace with your desired path
    bool isCrossing = solution.isPathCrossing(examplePath);

    cout << "Is the path crossing? " << (isCrossing ? "Yes" : "No") << endl;

    return 0;
}
