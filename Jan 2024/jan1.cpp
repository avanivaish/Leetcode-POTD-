#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans=0, i=0;
        for(int j=0; j<s.size(); j++){
            if(i<g.size() && g[i]<=s[j]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};

int main() {

    Solution solution;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int result = solution.findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;

    return 0;
}
