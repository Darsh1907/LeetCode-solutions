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
    int helper(TreeNode* root, int start, int& maxTime) {
        if (root == nullptr) return 0;
        int left = helper(root->left, start, maxTime);
        int right = helper(root->right, start, maxTime);
        if (root->val == start) {
            maxTime = max(maxTime, max(left, right));
            return -1;
        } 
        else if (left < 0 || right < 0) {
            maxTime = max(maxTime, abs(left) + abs(right));
            return min(left, right) - 1;
        }
        maxTime = max(maxTime, max(left, right));
        return max(left, right) + 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        int maxTime = 0;
        helper(root, start, maxTime);
        return maxTime;
    }
};