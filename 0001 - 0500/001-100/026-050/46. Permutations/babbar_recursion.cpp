class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()-1) ans.push_back(nums);
        else
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[i]); // backtrack to get initial string before swap
        } 
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};