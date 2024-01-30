#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>

using namespace std;  // Add this line to use the std namespace

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<long> stack;
    const unordered_map<string, function<long(long, long)>> op{
        {"+", std::plus<long>()},
        {"-", std::minus<long>()},
        {"*", std::multiplies<long>()},
        {"/", std::divides<long>()}};

    for (const string& token : tokens)
      if (op.count(token)) {
        const long b = stack.top();
        stack.pop();
        const long a = stack.top();
        stack.pop();
        stack.push(op.at(token)(a, b));
      } else {
        stack.push(stoi(token));
      }

    return stack.top();
  }
};

int main() {
    Solution solution;

    // Example 1: ["2", "1", "+", "3", "*"]
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Result 1: " << solution.evalRPN(tokens1) << endl;  // Output should be 9

    // Example 2: ["4", "13", "5", "/", "+"]
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Result 2: " << solution.evalRPN(tokens2) << endl;  // Output should be 6

    // Example 3: ["10", "6", "9", "3", "/", "-", "*"]
    vector<string> tokens3 = {"10", "6", "9", "3", "/", "-", "*"};
    cout << "Result 3: " << solution.evalRPN(tokens3) << endl;  // Output should be 36

    return 0;
}

