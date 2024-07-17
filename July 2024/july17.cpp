#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    dfs(root, {to_delete.begin(), to_delete.end()}, true, ans);
    return ans;
  }

 private:
  TreeNode* dfs(TreeNode*& root, const unordered_set<int>&& toDeleteSet,
                bool isRoot, vector<TreeNode*>& ans) {
    if (root == nullptr)
      return nullptr;

    const bool deleted = toDeleteSet.count(root->val);
    if (isRoot && !deleted)
      ans.push_back(root);

    // If root is deleted, both children have the possibility to be a new root
    root->left = dfs(root->left, move(toDeleteSet), deleted, ans);
    root->right = dfs(root->right, move(toDeleteSet), deleted, ans);
    return deleted ? nullptr : root;
  }
};

void printTree(TreeNode* root) {
  if (!root) return;
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
}

int main() {
  // Create the tree:
  //     1
  //    / \
  //   2   3
  //  / \   \
  // 4   5   6
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  // Nodes to delete
  vector<int> to_delete = {3, 5};

  // Solution
  Solution sol;
  vector<TreeNode*> forests = sol.delNodes(root, to_delete);

  // Print the resulting forest
  for (TreeNode* tree : forests) {
    printTree(tree);
    cout << endl;
  }

  return 0;
}
