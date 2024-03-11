class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        string result;
        for(int i=0; i<order.size(); i++) mp[order[i]]=0;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()) mp[s[i]]++;
        }
        for(int i=0; i<order.size(); i++) result.append(mp[order[i]], order[i]);
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) == mp.end()) result.push_back(s[i]);
        }
        return result;
    }
};