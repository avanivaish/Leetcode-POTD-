#include <iostream>
#include <stack>

using namespace std;

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            if (dfs(s1) != dfs(s2))
                return false;
        }
        return s1.empty() && s2.empty();
    }

    int dfs(stack<TreeNode*>& s) {
        while (true) {
            TreeNode* node = s.top();
            s.pop();
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);

            if (!node->left && !node->right) {
                return node->val;
            }
        }
    }
};

int main() {
    // Example usage:
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    // Add more nodes as needed

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(4);
    // Add more nodes as needed

    Solution solution;
    bool result = solution.leafSimilar(root1, root2);

    cout << "The two binary trees are " << (result ? "leaf-similar." : "not leaf-similar.") << endl;

    return 0;
}
