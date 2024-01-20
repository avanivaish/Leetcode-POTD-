#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    long ans = 0;
    // prevMin[i] := index k s.t. arr[k] is the previous minimum in arr[:i]
    vector<int> prevMin(n, -1);
    // nextMin[i] := index k s.t. arr[k] is the next minimum in arr[i + 1:]
    vector<int> nextMin(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && arr[stack.top()] > arr[i]) {
        const int index = stack.top();
        stack.pop();
        nextMin[index] = i;
      }
      if (!stack.empty())
        prevMin[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      ans += static_cast<long>(arr[i]) * (i - prevMin[i]) * (nextMin[i] - i);
      ans %= kMod;
    }

    return ans;
  }
};

int main() {
    // Example usage
    vector<int> input = {3, 1, 2, 4};
    
    Solution solution;
    int result = solution.sumSubarrayMins(input);
    
    cout << "Sum of minimum values for all subarrays: " << result << endl;

    return 0;
}
