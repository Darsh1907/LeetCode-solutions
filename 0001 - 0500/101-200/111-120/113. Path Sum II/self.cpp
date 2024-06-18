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
    inline bool isLeaf(TreeNode* root) {
        if(root->right || root->left) return false;
        return true;
    }
    void solve(TreeNode* root, int sum, int targetSum, vector<int> temp, vector<vector<int>>& res) {
        temp.push_back(root->val);
        sum += root->val;
        if(isLeaf(root)) {
            if(sum == targetSum) res.push_back(temp);
            return;
        }
        if(root->left) solve(root->left, sum, targetSum, temp, res);
        if(root->right) solve(root->right, sum, targetSum, temp, res);
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(root->val);
        if(root->left) solve(root->left, root->val, targetSum, temp, res);
        if(root->right) solve(root->right, root->val, targetSum, temp, res);
        // If root and leaf is same and sum==targetSum in that case
        if(!root->left && !root->right && root->val==targetSum) res.push_back({root->val});
        return res;
    }
};