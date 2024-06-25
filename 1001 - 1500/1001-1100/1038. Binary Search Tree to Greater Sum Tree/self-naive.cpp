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
    void inorderHelper(TreeNode* root, vector<int>& res) {
        if(root==NULL) return;
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
    void convert(TreeNode* root, unordered_map<int, int>& umap) {
        if(root==NULL) return;
        root->val = umap[root->val];
        convert(root->left, umap);
        convert(root->right, umap);
        return;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        int size = inorder.size();
        unordered_map<int, int> umap; // mapping of node actual value to the new value
        umap[inorder[size-1]] = inorder[size-1];
        for(int i=size-2; i>=0; i--) {
            umap[inorder[i]] = inorder[i] + umap[inorder[i+1]];
        }
        convert(root, umap);
        return root;
    }
};