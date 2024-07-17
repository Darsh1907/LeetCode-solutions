/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
*/

class Solution {
private:
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& result) {
        if(root == nullptr) return nullptr;
        root->left = deleteNodes(root->left, to_delete, result);
        root->right = deleteNodes(root->right, to_delete, result);
        if(to_delete.find(root->val) != to_delete.end()) {
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            // Returning null to indicate this node is deleted
            return nullptr; 
        }
        // Returning the root itself if it is not deleted
        return root; 
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        // Check if root itself should be added to result
        if (root && to_delete_set.find(root->val) == to_delete_set.end()) result.push_back(root);
        deleteNodes(root, to_delete_set, result);
        return result;
    }
};