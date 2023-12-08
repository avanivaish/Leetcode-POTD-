#include<iostream>
#include <string>
using namespace std;

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
    void solve(TreeNode* node, string& ans) {
        if (node == nullptr) return;

        ans.append(to_string(node->val));

        if (node->left != nullptr || node->right != nullptr) {
            ans.push_back('(');
            solve(node->left, ans);
            ans.push_back(')');
        }

        if (node->right != nullptr) {
            ans.push_back('(');
            solve(node->right, ans);
            ans.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution solution;
    string result = solution.tree2str(root);

    cout << "Result: " << result << endl;

    // Don't forget to free the allocated memory to avoid memory leaks
    // (In a real-world scenario, you might want to use smart pointers or a proper memory management strategy.)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
