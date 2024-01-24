#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int path, int& ans) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr) {
      path ^= 1 << root->val;
      if ((path & (path - 1)) == 0)
        ++ans;
      return;
    }

    dfs(root->left, path ^ 1 << root->val, ans);
    dfs(root->right, path ^ 1 << root->val, ans);
  }
};

int main() {
  // Example usage
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(1);

  Solution solution;
  int result = solution.pseudoPalindromicPaths(root);

  cout << "Number of pseudo-palindromic paths: " << result << endl;

  // Clean up allocated memory (not necessary for the main logic)
  delete root->left->left;
  delete root->left->right;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
