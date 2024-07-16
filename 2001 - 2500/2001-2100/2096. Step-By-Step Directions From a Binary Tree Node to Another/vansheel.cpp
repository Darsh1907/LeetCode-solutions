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
    string left, right;
    void solve(TreeNode* node,string &path,int p,int q) {
        if(node==nullptr) return;
        if(node->val==p) left=path;
        if(node->val==q) right=path;

        path.push_back('L');
        solve(node->left,path,p,q);
        path.pop_back(); 

        path.push_back('R');
        solve(node->right,path,p,q);
        path.pop_back(); 
    }
    TreeNode* lca(TreeNode* root,int p,int q) {
        if(root==nullptr) return nullptr;
        if(root->val==p || root->val==q) return root;

        TreeNode* leftans = lca(root->left,p,q);
        TreeNode* rightans = lca(root->right,p,q);

        if(leftans!=nullptr && rightans!=nullptr) return root;
        else if(leftans==nullptr && rightans!=nullptr) return rightans;
        else if(leftans!=nullptr && rightans==nullptr) return leftans;
        else return nullptr;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcanode = lca(root,startValue,destValue);
        string path = "";
        solve(lcanode,path,startValue,destValue);
        for(auto& ch:left) ch='U';
        return left+right;
    }
};