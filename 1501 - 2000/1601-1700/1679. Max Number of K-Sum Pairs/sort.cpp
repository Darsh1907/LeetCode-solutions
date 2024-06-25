class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        int count = 0;
        while(left < right) {
            int sum=nums[left] + nums[right];
            if(sum == k) {
                count++;
                left++;
                right--;
            }
            if(sum<k) left++;
            if(sum>k) right--;
        }
        return count;
    }
};