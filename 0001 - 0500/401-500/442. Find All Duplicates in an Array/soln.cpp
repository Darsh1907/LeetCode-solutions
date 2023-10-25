class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // encounter a number x -> make the number at xth position negative -> if some other number makes you go to the same position again, it means you have already encountered that number.
        // in short we use the same array to mark which numbers have been encountered.
        vector<int> ans;
        for(int i = 0; i < nums.size();i++){
            if(nums[abs(nums[i])-1] > 0) nums[abs(nums[i]) - 1] *= -1;
            else if(nums[abs(nums[i])-1] < 0) ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};