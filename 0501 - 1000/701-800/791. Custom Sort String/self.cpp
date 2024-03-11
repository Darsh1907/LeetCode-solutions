class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        string result;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        for(int i=0; i<order.size(); i++){
            if(mp.find(order[i])!=mp.end()){
                int freq = mp[order[i]];
                for(int j=0; j<freq; j++) result.push_back(order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto i=mp.begin(); i!=mp.end(); i++){
            int freq = i->second;
            for(int j=0; j<freq; j++) result.push_back(i->first);
        }
        return result;
    }
};