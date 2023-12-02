#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1 = "";
        string string2 = "";
        for (int i = 0; i < word1.size(); i++) {
            string1 += word1[i];
        }
        for (int i = 0; i < word2.size(); i++) {
            string2 += word2[i];
        }
        int l = max(string1.length(), string2.length());
        for (int i = 0; i < l; i++) {
            if (string1[i] != string2[i]) {
                return false;
            }
        }
        return true;
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
