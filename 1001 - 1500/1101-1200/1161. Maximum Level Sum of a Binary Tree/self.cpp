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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int res = 0; // res signifies the resultant level
        while(!q.empty()) {
            level++;
            int qsize = q.size();
            int sum = 0;
            // For every nodes in the level -> calculate sum and add other nodes.
            for(int i=0; i<qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            // check is the sum of the level exceeds previously encountered maxSum
            if(maxSum<sum) {
                maxSum = sum;
                res = level;
            }
        }
        return res;
    }
};