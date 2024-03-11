#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string customSortString(string order, string s) {
    string ans;
    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (const char c : order)
      while (count[c]-- > 0)
        ans += c;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        ans += c;

    return ans;
  }
};

int main() {
  Solution solution;
  string order = "cba";
  string s = "abcd";
  string result = solution.customSortString(order, s);
  cout << "Custom sorted string: " << result << endl;
  return 0;
}
