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

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int& index) {
        if(index>=preorder.size()) return NULL;
        if(preorder[index]<mini || preorder[index]>maxi) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder, mini, root->val, index);
        root->right = solve(preorder, root->val, maxi, index);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(preorder, INT_MIN, INT_MAX, index);
    }
};