// The basic idea behind this algorithm is to cancel out pairs of different elements.
// Since the majority element appears more than ⌊n/2⌋ times, even after canceling out
// all the pairs of different elements, the majority element will still be left.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==res) count++;
            if(nums[i]!=res) count--;
            if(count==0) res=nums[i+1];
        }
        return res;
    }
};