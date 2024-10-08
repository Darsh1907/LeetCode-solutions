class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // selection sort
        for (int i=0; i<n-1; i++) {
            int mini = i;
            for(int j=i+1; j<n; j++) {
                if(nums[j] < nums[mini]) mini = j;
            }
            int temp = nums[mini];
            nums[mini] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }
};
