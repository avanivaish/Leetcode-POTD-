#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ans = 0;

    for (const string& log : logs) {
      if (log == "./")
        continue;
      if (log == "../")
        ans = max(0, ans - 1);
      else
        ++ans;
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
  vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
  vector<string> logs3 = {"d1/", "../", "../", "../"};

  cout << "Test Case 1: " << solution.minOperations(logs1) << endl;
  cout << "Test Case 2: " << solution.minOperations(logs2) << endl;
  cout << "Test Case 3: " << solution.minOperations(logs3) << endl;

  return 0;
}
