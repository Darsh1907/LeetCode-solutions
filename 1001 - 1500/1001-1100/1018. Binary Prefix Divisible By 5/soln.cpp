class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> resp;
        int mod = 0;
        for(int i=0; i<nums.size(); i++) {
            int bit = nums[i];
            mod = (mod*2 + bit) % 5;
            resp.push_back(mod == 0);
        }
        return resp;
    }
};