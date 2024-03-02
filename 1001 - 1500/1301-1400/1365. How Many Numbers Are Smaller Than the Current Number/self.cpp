class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mymap;
        for(int i=0; i<nums.size(); i++) mymap[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(auto j=mymap.begin(); j->first!=nums[i]; j++){
                count = count + j->second;
            }
            nums[i] = count;
        }
        return nums;
    }
};