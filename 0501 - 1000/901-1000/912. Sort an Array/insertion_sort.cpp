class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // insertion sort
        for(int i=0; i<=n-1; i++) {
            int j=i;
            while (j>0 && nums[j-1] > nums[j]) {
                int temp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = temp;
                j--;
            }
        }
        return nums;
    }
};
