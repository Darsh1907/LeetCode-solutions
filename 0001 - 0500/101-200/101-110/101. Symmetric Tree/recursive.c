/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

bool isSymmetricHelper(struct TreeNode* leftNode, struct TreeNode* rightNode) {
    if(leftNode==NULL && rightNode==NULL) return true;
    if(leftNode==NULL || rightNode==NULL) return false;
    if(leftNode->val != rightNode->val) return false;
    return isSymmetricHelper(leftNode->left, rightNode->right) && isSymmetricHelper(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root==NULL) return true;
    return isSymmetricHelper(root->left, root->right);
}