/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

#include <climits>

int min(int *a, int *b) {if(*a<*b) return *a; return *b;}

int solve(struct TreeNode* root) {
    if(root->left==NULL && root->right==NULL) return 0;
    int left = INT_MAX;
    int right = INT_MAX;
    if(root->left) left = solve(root->left);
    if(root->right) right = solve(root->right);
    return 1 + min(&left, &right);
}

int minDepth(struct TreeNode* root) {
    if(root==NULL) return 0;
    return  1 + solve(root);
}