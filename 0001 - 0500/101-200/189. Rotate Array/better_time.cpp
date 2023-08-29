class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1) return;
        else if(k==0) return;
        k %= nums.size();
        vector<int> result;
        for(int i=(nums.size()-k); i<nums.size(); i++){
            result.push_back(nums[i]);
        }
        for(int i=0; i<nums.size()-k; i++){
            result.push_back(nums[i]);
        }
        nums.clear();
        nums = result;
    }
};