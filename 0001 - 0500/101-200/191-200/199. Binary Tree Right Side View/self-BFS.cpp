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

// This code is a simple modification in the level order traversal logic

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()) {
            res.push_back(q.back()->val); // for every level, get the rightmost element
            // (Node that is added at last in queue in level order traversal)
            int qsize = q.size();
            for(int i=0; i<qsize; i++) {
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
        }
        return res;
    }
};