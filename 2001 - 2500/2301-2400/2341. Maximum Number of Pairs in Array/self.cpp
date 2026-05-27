class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int nums0 = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(++mp[nums[i]]%2 == 0){
                mp.erase(nums[i]);
                nums0++;
            }
        }
        int nums1 = mp.size();
        return {nums0, nums1};
    }
};