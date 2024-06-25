#include <vector>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        for (int i = 1; i < inorderTraversal.size(); ++i) {
            if (inorderTraversal[i] <= inorderTraversal[i-1]) return false;
        }
        return true;
    }
private:
    void inorder(TreeNode* node, std::vector<int>& inorderTraversal) {
        if (!node) return;
        inorder(node->left, inorderTraversal);
        inorderTraversal.push_back(node->val);
        inorder(node->right, inorderTraversal);
    }
};
