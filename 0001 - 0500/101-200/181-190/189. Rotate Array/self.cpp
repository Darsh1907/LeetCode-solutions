class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(nums.size()==1 || k==0) return;
        vector<int> result;
        for(int i=(nums.size()-k); i<nums.size(); i++) result.push_back(nums[i]);
        for(int i=0; i<nums.size()-k; i++) result.push_back(nums[i]);
        nums.clear();
        nums = result;
    }
};