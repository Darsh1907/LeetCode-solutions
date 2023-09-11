class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]!=nums[i-1]) k++;
            if(k==3) return nums[i-1];
        }
        return nums[n-1];
    }
};