class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c=0, soln=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i=i+c) {
            c = count(nums.begin(),nums.end(),nums[i]);
            soln = soln + c*(c-1)/2;
        }
        return soln;
    }
};