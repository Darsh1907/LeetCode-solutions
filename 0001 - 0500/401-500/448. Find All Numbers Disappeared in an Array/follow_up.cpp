class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        // Mark elements as negative to indicate they've been encountered
        for (int i=0; i<size; i++) {
            // we need to take the absolute value of num when accessing the nums array because the value of num 
            // itself can be negative if it's been marked as encountered.
            int num = abs(nums[i]);
            if(nums[num-1]>0) nums[num-1]=nums[num-1]*(-1);
        }
        // Find the positive numbers, which indicate missing elements
        vector<int> result;
        for(int i=0; i<size; i++) {
            if(nums[i]>0) result.push_back(i+1);
        }
        return result;
    }
};