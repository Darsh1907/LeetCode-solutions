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
    // result is the lexigographically smallest string from root to leaf.
    // temp is the current string from root to current node.
    void solve(TreeNode* node, string& result, string temp) {
        temp.push_back(node->val + 'a');
        if (!node->right && !node->left) {
            // reverse the temp string to get the correct order.
            // check is the newly encountered string from root to leaf is smaller than the previous one.
            reverse(temp.begin(), temp.end());
            if(result=="") result = temp;
            else if (temp < result) result=temp;
            return;
        }
        else if (node->right!=nullptr && node->left!=nullptr) {
            // if both left and right child exists, then we need to check for both.
            solve(node->left, result, temp);
            solve(node->right, result, temp);
        }
        // if only one child exists, then we need to check for that child only.
        else if(node->right!=nullptr && node->left==nullptr) solve(node->right, result, temp);
        else if(node->right==nullptr && node->left!=nullptr) solve(node->left, result, temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string result;
        solve(root, result, "");
        return result;
    }
};