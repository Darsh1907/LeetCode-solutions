class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto a:ransomNote) mp[a]++;
        for(auto a:magazine) mp[a]--;
        for(auto a:mp) {
            if(a.second>0) return false;
        }
        return true;
    }
};