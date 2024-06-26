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
    // InorderTraversal using Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
    TreeNode* buildTreeHelper(vector<int>& nums, int start, int end) {
        // base cases
        if(start>end) return NULL;
        if(start == end) return new TreeNode(nums[start]);
        // Create new node
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        // Build trees for left and right of root
        root->left = buildTreeHelper(nums, start, mid-1);
        root->right = buildTreeHelper(nums, mid+1, end);
        // Return ans
        return root;
    }
    TreeNode* buildTree(vector<int>& nums) {
        // initialise search space
        int start = 0;
        int end = nums.size()-1;
        // create root node
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        // build trees on left and right of root
        root->left = buildTreeHelper(nums, start, mid-1);
        root->right = buildTreeHelper(nums, mid+1, end);
        // return result
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        TreeNode* ans = buildTree(inorder);
        return ans;
    }
};