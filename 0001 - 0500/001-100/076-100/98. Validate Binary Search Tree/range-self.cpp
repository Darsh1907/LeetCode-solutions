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
    bool validBSThelp(TreeNode* root, pair<long, long> validRange) {
        if (root == nullptr) return true;
        if (root->val <= validRange.first || root->val >= validRange.second) return false;
        if (!validBSThelp(root->left, {validRange.first, root->val})) return false;
        if (!validBSThelp(root->right, {root->val, validRange.second})) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validBSThelp(root, {LONG_MIN, LONG_MAX});
    }
};
