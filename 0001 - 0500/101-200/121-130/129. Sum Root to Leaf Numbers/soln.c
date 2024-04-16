/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

int solve(struct TreeNode* node, int pathSum) {
    if (!node) return 0;
    pathSum = pathSum*10 + node->val;
    if(!node->left && !node->right) return pathSum;
    return solve(node->left, pathSum) + solve(node->right, pathSum);
}

int sumNumbers(struct TreeNode* root) {
    return solve(root, 0);
}