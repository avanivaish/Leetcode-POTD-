#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> stack;
    string ans;

    for (const char c : s)
      if (c == '(') {
        stack.push(ans.length());
      } else if (c == ')') {
        // Reverse the corresponding substring between ().
        const int j = stack.top();
        stack.pop();
        reverse(ans.begin() + j, ans.end());
      } else {
        ans += c;
      }

    return ans;
  }
};

int main() {
  Solution solution;
  string input = "(u(love)i)";
  string result = solution.reverseParentheses(input);
  cout << "Result: " << result << endl;
  return 0;
}
