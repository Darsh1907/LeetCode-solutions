class Solution {
public:
    // This function will return sorted array. Then the question is converted into
    // Two Sum II - Input array is sorted.
    void inorder(TreeNode* root, vector<int>& inorderVal) {
        if (root == NULL) return;
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root, inorderVal);
        int i = 0;
        int j = inorderVal.size() - 1;
        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }
};