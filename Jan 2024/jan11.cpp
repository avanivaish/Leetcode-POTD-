#include <iostream>

using namespace std;  // Add this line to use the std namespace

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
    int maxDiff(TreeNode* node, int maxval, int minval){
        if(node==NULL) return(maxval-minval);
        maxval = max(node->val, maxval);
        minval = min(node->val, minval);
        int maxLeftDiff = maxDiff(node->left, maxval, minval);
        int maxRightDiff = maxDiff(node->right, maxval, minval);
        return max(maxLeftDiff, maxRightDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        return maxDiff(root, root->val, root->val);
    }
};

int main() {
    // Example usage

    // Creating a binary tree
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // Creating an instance of the Solution class
    Solution solution;

    // Calculating the maximum ancestor difference using the maxAncestorDiff function
    int result = solution.maxAncestorDiff(root);

    // Outputting the result
    cout << "Maximum Ancestor Difference: " << result << endl;

    // Remember to free the allocated memory for the tree nodes to avoid memory leaks
    // You can create a separate function for this purpose or use a recursive function

    return 0;
}
