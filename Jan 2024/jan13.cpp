#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        int ans = 0;
        for(auto el:freq){
            if(el.second>0){
                ans += el.second;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;

    // Example usage
    string s = "leetcode";
    string t = "practice";

    int result = solution.minSteps(s, t);

    cout << "Minimum steps to make the strings anagrams: " << result << endl;

    return 0;
}
