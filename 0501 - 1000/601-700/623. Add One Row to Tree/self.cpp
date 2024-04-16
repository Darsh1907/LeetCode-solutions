/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
*/

class Solution {
private:
    void solve(TreeNode* root, int val, int depth) {
        if (depth == 2) {
            TreeNode* left_subtree = new TreeNode(val, root->left, nullptr);
            TreeNode* right_subtree = new TreeNode(val, nullptr, root->right);
            root->left = left_subtree;
            root->right = right_subtree;
            return;
        }
        if(root->right != nullptr) solve(root->right, val, depth - 1);
        if(root->left != nullptr) solve(root->left, val, depth - 1);
        return;
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newroot = new TreeNode(val, root, nullptr);
            return newroot;
        }
        solve(root, val, depth);
        return root;
    }
};