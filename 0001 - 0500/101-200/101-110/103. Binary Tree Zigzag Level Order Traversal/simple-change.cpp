// This program is a simple change made to the solution of LeetCode 102. Binary Tree Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine the position to fill based on the current direction
                int index;
                if(leftToRight) index=i;
                else index=size-1-i;
                temp[index] = node->val;

                // Push children to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // After the level is done, flip the order
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};