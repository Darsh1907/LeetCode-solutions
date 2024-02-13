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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) root = new TreeNode(val);
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(val > curr->val) {
                if(curr->right == nullptr) curr->right = new TreeNode(val);
                else curr = curr->right;
            }
            else if (val < curr->val){
                if(curr->left == nullptr) curr->left=new TreeNode(val);
                else curr=curr->left; 
            }
            if(curr->val == val) return root;
        }
        return root;
    }
};