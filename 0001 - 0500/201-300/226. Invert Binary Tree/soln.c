/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

void solve(struct TreeNode* root){
    if(root==NULL) return;
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    solve(root->left);
    solve(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    solve(root);
    return root;
}