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
    int getmaxi(vector<int>& nums, int start, int end) {
        int maxi = start;
        for(int i=start+1; i<=end; i++) {
            if(nums[i] > nums[maxi]) maxi = i;
        }
        return maxi;
    }
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        // base cases
        if(start>end) return NULL;
        if(start == end) return new TreeNode(nums[start]);

        // Create new node
        int maxi = getmaxi(nums, start, end);
        TreeNode* root = new TreeNode(nums[maxi]);

        // Build trees for left and right of root
        root->left = buildTree(nums, start, maxi-1);
        root->right = buildTree(nums, maxi+1, end);

        // Return ans
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // initialise search space
        int start = 0;
        int end = nums.size()-1;

        // create root node
        int maxi = getmaxi(nums, start ,end);
        TreeNode* root = new TreeNode(nums[maxi]);

        // build trees on left and right of root
        root->left = buildTree(nums, start, maxi-1);
        root->right = buildTree(nums, maxi+1, end);

        // return result
        return root;
    }   
};