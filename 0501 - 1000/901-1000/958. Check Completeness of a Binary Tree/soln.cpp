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

class Solution {
private:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCBT(TreeNode* root, int index, int total) {
        if(root==NULL) return true;
        if(index >= total) return false;
        return isCBT(root->right, 2*index+2, total) && isCBT(root->left, 2*index+1, total);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return isCBT(root, 0, totalNodes);
    }
};