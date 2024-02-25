class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        int max_freq = 0;
        int result = 0;
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second > max_freq){
                max_freq = i->second;
                result = i->second;
            }
            else if(i->second == max_freq) result = result + i->second;
        }
        return result;
    }
};