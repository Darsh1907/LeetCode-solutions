class Solution {
public:
    TreeNode* maketree(vector<int>& nums, int l, int r, TreeNode* root) {
        if(l>r)return NULL;
        int mid = (l + r) / 2;
        TreeNode* newnode=new TreeNode(nums[mid]);
        newnode->left=maketree(nums,l,mid-1,newnode);
        newnode->right=maketree(nums,mid+1,r,newnode);
        return newnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return maketree(nums,0,n-1,NULL);
    }
};