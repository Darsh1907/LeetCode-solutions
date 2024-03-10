class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        for(int i=0; i<words1.size(); i++) mp[words1[i]]++;
        for(int i=0; i<words2.size(); i++){
            if(mp[words2[i]]<=1) mp[words2[i]]--;
        }
        int result = 0;
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second == 0) result++;
        }
        return result;
    }
};