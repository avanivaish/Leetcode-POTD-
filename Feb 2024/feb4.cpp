#include<iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }
        
        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c] = 1 + countT[c];
        }
        
        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int reslen = numeric_limits<int>::max();
        int l = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            window[c] = 1 + window[c];
            
            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }
            
            while (have == need) {
                if ((r - l + 1) < reslen) {
                    res = {l, r};
                    reslen = r - l + 1;
                }
                
                window[s[l]]--;
                
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                
                l++;
            }
        }
        
        int start = res.first, end = res.second;
        return (start == -1 || end == -1) ? "" : s.substr(start, end - start + 1);
    }
};


int main() {
    Solution solution;

    // Example usage
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);

    // Display the result
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}
