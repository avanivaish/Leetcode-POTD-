#include <vector>

using namespace std;

// Definition for a binary tree node.
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
  int countPairs(TreeNode* root, int distance) {
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
  }

 private:
  vector<int> dfs(TreeNode* root, int distance, int& ans) {
    vector<int> d(distance + 1);  // {distance: the number of leaf nodes}
    if (root == nullptr)
      return d;
    if (root->left == nullptr && root->right == nullptr) {
      d[0] = 1;
      return d;
    }

    const vector<int> dl = dfs(root->left, distance, ans);
    const vector<int> dr = dfs(root->right, distance, ans);

    for (int i = 0; i < distance; ++i)
      for (int j = 0; j < distance; ++j)
        if (i + j + 2 <= distance)
          ans += dl[i] * dr[j];

    for (int i = 0; i < distance; ++i)
      d[i + 1] = dl[i] + dr[i];

    return d;
  }
};

int main() {
  // Example usage
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  Solution solution;
  int distance = 3;
  int result = solution.countPairs(root, distance);

  // Output the result
  cout << "Number of good leaf node pairs: " << result << endl;

  // Clean up the allocated tree nodes
  delete root->left->left;
  delete root->left->right;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
