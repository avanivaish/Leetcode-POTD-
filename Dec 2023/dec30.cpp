#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include the algorithm header

using namespace std; // Adding the namespace

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26);

        for (const string& word : words)
            for (const char c : word)
                ++count[c - 'a'];

        // Use std::all_of
        return std::all_of(count.begin(), count.end(), [&](const int c) { return c % words.size() == 0; });
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example vector of strings
    vector<string> words = {"abc", "def", "ghi"};

    // Calling the makeEqual function from the Solution class
    bool result = solution.makeEqual(words);

    // Displaying the result
    if (result) {
        cout << "The characters can be rearranged to make all strings equal in length." << endl;
    } else {
        cout << "The characters cannot be rearranged to make all strings equal in length." << endl;
    }

    return 0;
}
