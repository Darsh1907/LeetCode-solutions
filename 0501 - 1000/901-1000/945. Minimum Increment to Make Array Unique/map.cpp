class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0;
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->second > 1) {
                mp[i->first + 1] += i->second-1;
                res += (i->second - 1);
            }
        }
        return res;
    }
};