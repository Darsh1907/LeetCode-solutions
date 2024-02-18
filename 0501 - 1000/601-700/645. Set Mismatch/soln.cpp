class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeated = -1;
        for(int i=0; i<nums.size(); i++){
            int curr = abs(nums[i]);
            if(nums[curr-1] < 0) repeated = curr;
            else nums[curr-1] *= -1;
        }
        int missing = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) missing=i+1;
        }
        return {repeated, missing};
    }
};