#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;

        for (auto description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            int isLeft = description[2];

            TreeNode* parentNode = nullptr;
            TreeNode* childNode = nullptr;

            if (mp.find(parentVal) == mp.end()) parentNode = new TreeNode(parentVal);
            else parentNode = mp[parentVal];

            if (mp.find(childVal) == mp.end()) childNode = new TreeNode(childVal);
            else childNode = mp[childVal];

            if (isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasParent[childVal] = true;
            mp[childVal] = childNode;
            mp[parentVal] = parentNode;
        }

        TreeNode* rootNode = nullptr;
        for (auto& [nodeVal, node] : mp) {
            if (!hasParent[nodeVal]) rootNode = node;
        }

        return rootNode;
    }
};

// Helper function to print the tree in pre-order traversal
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<vector<int>> descriptions = {
        {1, 2, 1},
        {1, 3, 0},
        {2, 4, 1},
        {2, 5, 0}
    };

    Solution sol;
    TreeNode* root = sol.createBinaryTree(descriptions);

    // Print the tree in pre-order traversal
    printTree(root);
    cout << endl;

    return 0;
}
