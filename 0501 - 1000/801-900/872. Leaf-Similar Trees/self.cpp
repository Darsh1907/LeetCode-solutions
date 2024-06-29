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
    inline bool isLeaf(TreeNode* root) {
        if(root->left || root->right) return false;
        return true;
    }
    void getLeafSeq(TreeNode* root, vector<int>& seq) {
        if(root==NULL) return;
        if(isLeaf(root)) {
            seq.push_back(root->val);
            return;
        }
        getLeafSeq(root->left, seq);
        getLeafSeq(root->right, seq);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        getLeafSeq(root1, seq1);
        vector<int> seq2;
        getLeafSeq(root2, seq2);
        return (seq1 == seq2);
    }
};