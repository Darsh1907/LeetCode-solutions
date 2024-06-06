class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        while(mp.begin()!=mp.end()) {
            auto i = mp.begin();
            vector<int> toTake;
            vector<int> toErase;
            for(int cnt=0; cnt<k; cnt++) {
                if(i==mp.end()) return false;
                toTake.push_back(i->first);
                if(toTake.size()>1 && (toTake.back()-1 != toTake[toTake.size()-2])) return false;
                i->second--;
                if(i->second == 0) toErase.push_back(i->first);
                i++;
            }
            for(int er=0; er<toErase.size(); er++) mp.erase(toErase[er]);
        }
        return true;
    }
};