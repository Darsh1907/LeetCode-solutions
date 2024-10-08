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

// Time Complexity = O(nlogn)
// Space Complexity = O(n)

class Solution {
    TreeNode* solve(unordered_map<int, int>& inorder_map, vector<int>& preorder, int& index, int inorderStart, int inorderEnd) {
        // base case
        if(index >= inorder_map.size() || inorderStart>inorderEnd) return NULL;
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = inorder_map[element];
        // recursive call
        root->left = solve(inorder_map, preorder, index, inorderStart, position-1);
        root->right = solve(inorder_map, preorder, index, position+1, inorderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        // Instead of inorder, we will give inorder_map for optimising speed.
        unordered_map<int, int> inorder_map;
        for(int i=0; i<inorder.size(); i++) inorder_map[inorder[i]] = i;
        TreeNode* ans = solve(inorder_map, preorder, preorderIndex, 0, preorder.size()-1);
        return ans;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        TreeNode* ans = buildTree(preorder, inorder);
        return ans;
    }
};