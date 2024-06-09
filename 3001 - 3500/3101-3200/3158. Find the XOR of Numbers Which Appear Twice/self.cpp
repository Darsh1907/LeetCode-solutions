class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res=0;
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) res^=nums[i];
            else s.insert(nums[i]);
        }
        return res;
    }
};