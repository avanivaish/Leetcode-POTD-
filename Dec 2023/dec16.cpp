#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example usage:
    string input1 = "listen";
    string input2 = "silent";

    if (solution.isAnagram(input1, input2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
