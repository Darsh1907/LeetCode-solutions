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

// Hint1: Create a datastructure with 4 parameters: (sum, isBST, maxLeft, minRight).
// Hint2: In each node compute theses parameters, following the conditions of a Binary Search Tree.
// Reference: https://www.youtube.com/watch?v=fqx8z3VepMA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=79

class info {
public:
    int max; // max value in that subtree
    int min; // min value in that subtree
    bool isBST; // is that subtree a BST
    int sum; // sum of all nodes in that BST
};

class Solution {
private:
info solve(TreeNode * root, int& ans) {
    // base case - when root is null
    if(root==NULL) return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info currNode;

    if(left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
        currNode.isBST = true;
        currNode.sum = left.sum + right.sum + root->val;
        currNode.max = max(root->val, right.max);
        currNode.min = min(root->val, left.min);
        // anser update
        ans = max(ans, currNode.sum);
    }
    else currNode.isBST = false; // we wont update sum, max and min if the subtree is not a BST. It wont affect further calculations.
    
    // return the currNode
    return currNode;
}
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info temp = solve(root, maxSum);
        return maxSum;
    }
};