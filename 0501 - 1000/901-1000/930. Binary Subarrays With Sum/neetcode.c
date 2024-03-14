// Refer to the NeetCode video for explanation of this code
// https://www.youtube.com/watch?v=j4JDr4-jvo4

// The function calculcates number of subarr with sum<=x
int helper(int* nums, int numsSize, int x){
    if(x<0) return 0;
    int res = 0;
    int l=0, curr=0;
    for(int r=0; r<numsSize; r++){
        curr = curr+nums[r];
        while(curr > x){
            curr = curr - nums[l];
            l++;
        }
        res = res + (r-l+1);
    }
    return res;
}

int numSubarraysWithSum(int* nums, int numsSize, int goal){
    // Return difference between <=goal and <=(goal-1).
    // This will result in number of subarrys with sum exactly equal to goal.
    return helper(nums, numsSize, goal) - helper(nums, numsSize, goal-1);
}