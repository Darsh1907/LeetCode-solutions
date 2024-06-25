class Solution {
private:
    void inOrder(TreeNode* root, int& k, int& result) {
        if(root == nullptr) return;
        inOrder(root->left, k, result);
        if(--k == 0) {
            result = root->val;
            return;
        }
        inOrder(root->right, k, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inOrder(root, k, result);
        return result;
    }
};