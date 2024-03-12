class Solution {
public:
    void swap(vector<int>& nums, int i, int l){
        int temp = nums[i];
        nums[i] = nums[l];
        nums[l] = temp;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        recurPermute(nums, 0, nums.size()-1, current, result);
        return result;
    }

    void recurPermute(vector<int>& nums, int left, int right, vector<int> current, vector<vector<int>>& result){
        if(left == right){
            result.push_back(nums);
            return;
        }
        
        for(int i = left; i <= right; i++){
            swap(nums, i, left);
            recurPermute(nums, left+1, right, current, result);
            // current.push_back(nums);
            swap(nums, i, left);
        }
    }

};