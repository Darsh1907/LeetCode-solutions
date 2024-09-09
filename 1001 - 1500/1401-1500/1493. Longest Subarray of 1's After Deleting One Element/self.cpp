class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zcount = 0;
        int ocount = 0;
        int l=0, r=0;
        int res = INT_MIN;
        while(r<nums.size()) {
            if(nums[r]==0) zcount++;
            else ocount++;
            while(zcount > 1) {
                if(nums[l]==0) zcount--;
                else ocount--;
                l++;
            }
            res = max(res, zcount+ocount);
            r++;
        }
        return res-1;
    }
};