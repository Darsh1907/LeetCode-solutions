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
    int findPos(vector<int>& inorder, int element) {
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i]==element) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd) {
        // base case
        if(index >=inorder.size() || inorderStart>inorderEnd) return NULL;
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPos(inorder, element);
        // recursive call
        root->left = solve(inorder, preorder, index, inorderStart, position-1);
        root->right = solve(inorder, preorder, index, position+1, inorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        TreeNode* ans = solve(inorder, preorder, preorderIndex, 0, preorder.size()-1);
        return ans;
    }
};