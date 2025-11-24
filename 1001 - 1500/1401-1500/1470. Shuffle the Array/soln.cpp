class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> resp;
        for(int i=0; i<n; i++) {
            resp.push_back(nums[i]);
            resp.push_back(nums[i+n]);
        }
        return resp;
    }
};