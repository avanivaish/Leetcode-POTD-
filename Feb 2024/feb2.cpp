#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    queue<int> q{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    while (!q.empty()) {
      const int num = q.front();
      q.pop();
      if (num > high)
        return ans;
      if (low <= num && num <= high)
        ans.push_back(num);
      const int lastDigit = num % 10;
      if (lastDigit < 9)
        q.push(num * 10 + lastDigit + 1);
    }

    return ans;
  }
};

int main() {
    Solution solution;
    int low = 100;
    int high = 300;

    vector<int> result = solution.sequentialDigits(low, high);

    cout << "Sequential digits between " << low << " and " << high << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
