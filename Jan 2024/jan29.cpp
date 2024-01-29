#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
 public:
  void push(int x) {
    input.push(x);
  }

  int pop() {
    peek();
    const int val = output.top();
    output.pop();
    return val;
  }

  int peek() {
    if (output.empty())
      while (!input.empty())
        output.push(input.top()), input.pop();
    return output.top();
  }

  bool empty() {
    return input.empty() && output.empty();
  }

 private:
  stack<int> input;
  stack<int> output;
};

int main() {
  MyQueue myQueue;

  myQueue.push(1);
  myQueue.push(2);
  cout << "Front element: " << myQueue.peek() << endl; // Output: 1
  cout << "Popped element: " << myQueue.pop() << endl; // Output: 1
  cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl; // Output: No

  return 0;
}
