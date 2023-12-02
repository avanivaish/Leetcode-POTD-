#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int m = 0, n = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][m] != word2[j][n]) {
                return false;
            }
            m++;
            n++;
            if (m >= word1[i].size()) {
                i++;
                m = 0;
            }
            if (n >= word2[j].size()) {
                j++;
                n = 0;
            }
        }
        return (i == word1.size() && j == word2.size());
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};
    
    bool result = solution.arrayStringsAreEqual(word1, word2);

    cout << "The two arrays of strings are " << (result ? "equal." : "not equal.") << endl;

    return 0;
}
