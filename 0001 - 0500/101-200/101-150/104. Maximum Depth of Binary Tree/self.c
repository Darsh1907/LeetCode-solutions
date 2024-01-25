/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

int max(int num1, int num2){
    if(num1>num2) return num1;
    else return num2;
}

int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    else if(root->left==NULL) return maxDepth(root->right)+1;
    else if(root->right==NULL) return maxDepth(root->left)+1;
    else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}