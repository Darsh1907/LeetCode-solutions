// Logic:
// Similar to soln1.cpp, the only difference is that for every element picked, we start from the other end to check.

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        int ct=0;
        while(low<nums.size()-1){
            if(nums[low]+nums[high]<target && low<high){
                ct=ct+(high-low);
                low++;
                high=nums.size()-1;
            }
            else if(nums[low]+nums[high]>=target && low<high) high--;
            else break;
        }
        return ct;   
    }
};