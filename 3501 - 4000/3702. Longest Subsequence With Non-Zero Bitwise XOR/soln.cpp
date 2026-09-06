class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int numsSize = nums.size();
        int totalXor = 0;
        bool isAllZero = true;
        for(int i=0; i<numsSize; i++) {
            totalXor = totalXor ^ nums[i];
            if(nums[i]!=0) isAllZero = false;
        }
        if(totalXor != 0) return numsSize;
        if(isAllZero) return 0;
        return numsSize-1;
    }
};