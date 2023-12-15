#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities_outgoing;
        unordered_set<string> cities_incoming;

        // Populate sets with outgoing and incoming cities
        for (const auto& path : paths) {
            cities_outgoing.insert(path[0]);
            cities_incoming.insert(path[1]);
        }

        // Find the city without any outgoing path
        for (const auto& city : cities_incoming) {
            if (cities_outgoing.find(city) == cities_outgoing.end()) {
                return city;
            }
        }

        // It is guaranteed that there will be exactly one destination city,
        // so this return statement is not strictly necessary.
        return "";
    }
};

// Example usage:
int main() {
    Solution solution;

    vector<vector<string>> paths1 = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    cout << solution.destCity(paths1) << endl;  // Output: "Sao Paulo"

    vector<vector<string>> paths2 = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    cout << solution.destCity(paths2) << endl;  // Output: "A"

    vector<vector<string>> paths3 = {{"A", "Z"}};
    cout << solution.destCity(paths3) << endl;  // Output: "Z"

    return 0;
}
