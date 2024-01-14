#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;  // Add this line

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        vector<int> count1_freq(26, 0), count2_freq(26, 0);
        vector<bool> count1_isPresent(26, false), count2_isPresent(26, false);
        // Count occurrences of characters in both words
        for (char ch : word1) {
            count1_freq[ch - 'a']++;
            count1_isPresent[ch - 'a'] = true;
        }
        for (char ch : word2) {
            count2_freq[ch - 'a']++;
            count2_isPresent[ch - 'a'] = true;
        }
        sort(begin(count1_freq), end(count1_freq));
        sort(begin(count2_freq), end(count2_freq));

        return(count1_freq == count2_freq && count1_isPresent == count2_isPresent);
    }
};

int main() {
    Solution solution;

    // Test cases
    string word1 = "abc", word2 = "bca";
    bool result = solution.closeStrings(word1, word2);
    
    cout << "Are '" << word1 << "' and '" << word2 << "' close strings? " << (result ? "Yes" : "No") << endl;

    // Add more test cases as needed

    return 0;
}
