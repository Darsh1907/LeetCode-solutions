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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // Base Case
        if (root == NULL) return result;
        // Create an empty stack and push root to it
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        /* Pop all items one by one. Do following for every popped item
        a) print it
        b) push its right child
        c) push its left child
        Note that right child is pushed first so that left is processed first */
        while (nodeStack.empty() == false) {
            // Pop the top item from stack and print it
            TreeNode* node = nodeStack.top();
            // printf("%d ", node->data);
            result.push_back(node->val);
            nodeStack.pop();
            // Push right and left children of the popped node to stack
            if (node->right) nodeStack.push(node->right);
            if (node->left) nodeStack.push(node->left);
        }
        return result;
    }
};