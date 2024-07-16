#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string pathToStart;
    string pathToDest;

    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);

    while (!pathToStart.empty() && !pathToDest.empty() &&
           pathToStart.back() == pathToDest.back()) {
      pathToStart.pop_back();
      pathToDest.pop_back();
    }

    return string(pathToStart.length(), 'U') +
           string(pathToDest.rbegin(), pathToDest.rend());
  }

 private:
  bool dfs(TreeNode* root, int val, string& path) {
    if (root->val == val)
      return true;
    if (root->left && dfs(root->left, val, path))
      path.push_back('L');
    else if (root->right && dfs(root->right, val, path))
      path.push_back('R');
    return !path.empty();
  }
};

int main() {
  // Constructing the binary tree
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int startValue = 3;
  int destValue = 7;

  Solution solution;
  string result = solution.getDirections(root, startValue, destValue);
  cout << "Directions from " << startValue << " to " << destValue << ": " << result << endl;

  // Cleaning up allocated memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
