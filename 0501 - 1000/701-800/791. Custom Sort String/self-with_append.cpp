class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        string result;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        for(int i=0; i<order.size(); i++){
            if(mp.find(order[i])!=mp.end()){
                result.append(mp[order[i]], order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto i=mp.begin(); i!=mp.end(); i++) result.append(i->second, i->first);
        return result;
    }
};