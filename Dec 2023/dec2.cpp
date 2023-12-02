#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
        for (char &ch : chars) {
            charCount[ch - 'a']++;
        }
        int result = 0;
        for (string &word : words) {
            vector<int> wordCount(26, 0);
            for (char &ch : word) {
                wordCount[ch - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (charCount[i] < wordCount[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok == true) {
                result += word.length();
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    
    int result = solution.countCharacters(words, chars);

    cout << "Result: " << result << endl;

    return 0;
}
