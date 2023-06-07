class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int newsize = 2*nums.size();
        for(int i=0; i<newsize; i++){
            ans.push_back(nums[i%nums.size()]);
        }
        return ans;
    }
};