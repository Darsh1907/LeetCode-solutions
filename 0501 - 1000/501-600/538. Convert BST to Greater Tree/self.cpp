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
    void traverse(TreeNode* root, int& currSum) {
        if(root==NULL) return;
        traverse(root->right, currSum);
        currSum += root->val;
        root->val = currSum;
        traverse(root->left, currSum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int currSum = 0;
        traverse(root, currSum);
        return root;
    }
};