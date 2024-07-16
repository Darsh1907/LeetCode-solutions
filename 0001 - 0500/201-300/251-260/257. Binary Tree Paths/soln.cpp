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
    inline bool isLeaf(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    void solve(TreeNode* root, string temp, vector<string>& res) {
        if(temp.size()>0) temp += "->";
        temp += (to_string(root->val));
        if(isLeaf(root)) {
            res.push_back(temp);
            return;
        }
        if(root->left) solve(root->left, temp, res);
        if(root->right) solve(root->right, temp, res);
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp;
        solve(root, temp, res);
        return res;
    }
};