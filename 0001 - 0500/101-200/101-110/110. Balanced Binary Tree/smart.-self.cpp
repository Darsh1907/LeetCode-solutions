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
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    pair<bool, int> isBalancedFast(TreeNode* root) {
        // bool is to check is the tree is balanced, int is the height of the tree
        if(root == NULL) { // base case
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        if(!leftAns) return {false, 0};

        bool rightAns = right.first;
        if(!rightAns) return {false, 0};
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        if(abs(left.second - right.second) <=1) ans.first = true;
        else ans.first = false;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};