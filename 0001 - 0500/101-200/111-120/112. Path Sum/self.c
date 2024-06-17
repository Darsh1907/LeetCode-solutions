/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

bool solve(struct TreeNode* root, int targetSum, int sum) {
    if (root == NULL) return false;
    sum += root->val;
    // Check if it is a leaf node
    if(root->left == NULL && root->right == NULL) return sum == targetSum;
    // Recur for left and right subtrees
    bool left = solve(root->left, targetSum, sum);
    bool right = solve(root->right, targetSum, sum);
    return left || right;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return solve(root, targetSum, 0);
}