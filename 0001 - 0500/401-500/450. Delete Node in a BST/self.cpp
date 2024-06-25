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
    inline bool isLeaf(TreeNode* root) {
        if(root->right==NULL && root->left==NULL) return true;
        return false;
    }
    int getMin(TreeNode* root) {
        while (root->left != nullptr) root = root->left;
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        // if u found the node to be deleted
        if(root->val == key) {
            // if the node  is a leaf node
            if(isLeaf(root)) {
                delete root;
                return NULL;
            }
            // if the node has only 1 right child
            if(root->left==NULL) {
                TreeNode* returnNode = root->right;
                delete root;
                return returnNode;
            }
            // if the node has only 1 left child
            if(root->right==NULL) {
                TreeNode* returnNode = root->left;
                delete root;
                return returnNode;
            }
            // if the node has both left and right child
            else {
                int replaceNum = getMin(root->right);
                root->val = replaceNum;
                root->right = deleteNode(root->right, replaceNum);
                return root;
            }
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else root->left = deleteNode(root->left, key);
        return root;
    }
};