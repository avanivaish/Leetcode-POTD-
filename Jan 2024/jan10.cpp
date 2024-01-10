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

#include<iostream>
#include<bits/stdc++.h>
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
    void convert(TreeNode* node, int parent, unordered_map<int,vector<int>>&gr){
        if(node==NULL)return;
        vector<int>& adjacentList = gr[node->val];
        if(parent!=0) adjacentList.push_back(parent);
        if(node->left!=NULL) adjacentList.push_back(node->left->val);
        if(node->right!=NULL) adjacentList.push_back(node->right->val);

        convert(node->left, node->val, gr);
        convert(node->right, node->val, gr);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> gr;
        convert(root, 0, gr);
        queue<int> q;
        q.push(start);
        int min = 0;
        unordered_set<int> visited;
        visited.insert(start);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                for(int child:gr[node]){
                    if(visited.find(child)==visited.end()){
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            min++;
        }
        return min-1;
    }
};
int main() {
    // Example usage
    Solution solution;

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int startNode = 4; // Starting node for the BFS traversal

    int result = solution.amountOfTime(root, startNode);

    // Displaying the result
    cout << "Amount of time to reach all nodes from node " << startNode << ": " << result << endl;

    // Clean up the memory (optional but recommended)
    // Your actual program may have different memory management practices
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
