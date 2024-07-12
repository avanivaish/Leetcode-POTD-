#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int pointsForString(string &s, string maqsadString, int point) {
        int totalPoints = 0, n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.size() == 0) {
                st.push(s[i]);
            } else {
                if (s[i] == maqsadString[1] && st.top() == maqsadString[0]) {
                    st.pop();
                    totalPoints += point;
                } else {
                    st.push(s[i]);
                }
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return totalPoints;
    }
    
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y) swap(s1, s2), swap(x, y);

        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};

int main() {
    Solution solution;
    string s;
    int x, y;

    // Input example
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    int result = solution.maximumGain(s, x, y);
    cout << "Maximum Gain: " << result << endl;

    return 0;
}
