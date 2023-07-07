class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue; // Check for duplicates
            int left = i+1;
            int right = n-1;
            while (left<right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++; // Handle duplicates
                    while(left<right && nums[right]==nums[right+1]) right--; // Handle duplicates
                } 
                else if(sum < 0) left++;
                else right--;
            }
        }
        return result;
    }
};