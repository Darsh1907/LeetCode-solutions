class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> cnt(nums.size(),0);
        for(int i = 0; i<nums.size(); i++) {
            if(cnt[nums[i]] == 1) return nums[i];
            cnt[nums[i]]++;
        }
        return -1;
    }
};