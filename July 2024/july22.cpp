#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int, string>> heightAndNames;

        for (int i = 0; i < names.size(); ++i)
            heightAndNames.emplace_back(heights[i], names[i]);

        ranges::sort(heightAndNames, greater<>());

        for (const auto& [_, name] : heightAndNames)
            ans.push_back(name);

        return ans;
    }
};

int main() {
    // Test case
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<int> heights = {165, 170, 160};

    Solution solution;
    vector<string> sortedNames = solution.sortPeople(names, heights);

    // Print sorted names
    for (const string& name : sortedNames) {
        cout << name << " ";
    }

    cout << endl;

    return 0;
}
