// Refer the 105. Construct Binary Tree from Preorder and Inorder Traversal first and then solve this problem.

#include <vector>
#include <unordered_map>
using namespace std;

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
private:
    TreeNode* solve(unordered_map<int, int>& inorder_map, vector<int>& postorder, int& index, int inorderStart, int inorderEnd) {
        // base case
        if(index<0 || inorderStart>inorderEnd) return NULL;
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = inorder_map[element];
        // recursive call -> right and then left
        root->right = solve(inorder_map, postorder, index, position+1, inorderEnd);
        root->left = solve(inorder_map, postorder, index, inorderStart, position-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;
        // Instead of inorder, we will give inorder_map for optimising speed.
        unordered_map<int, int> inorder_map;
        // Constructing the map
        for(int i=0; i<inorder.size(); i++) inorder_map[inorder[i]] = i;
        TreeNode* ans = solve(inorder_map, postorder, postorderIndex, 0, postorderIndex);
        return ans;
    }
};