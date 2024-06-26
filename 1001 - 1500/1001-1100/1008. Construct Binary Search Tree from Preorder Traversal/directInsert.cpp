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

// Time Complexity = O(n^2)
// Space Complexity = O(n)

class Solution {
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if(val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;  
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0; i<preorder.size(); i++) {
            root = insertIntoBST(root, preorder[i]);
        }
        return root;
    }
};