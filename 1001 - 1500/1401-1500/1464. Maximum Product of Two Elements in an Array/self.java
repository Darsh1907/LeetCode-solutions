class Solution {
    public int maxProduct(int[] nums) {
        int numsSize = nums.length;
        int max = nums[0];
        int sec_max = 0;
        for(int i = 1; i < numsSize; i++) {
            if(nums[i] > max) {
                sec_max = max;
                max = nums[i];
            }
            else if(nums[i] > sec_max) sec_max = nums[i];
        }
        return (max - 1) * (sec_max - 1);
    }
}