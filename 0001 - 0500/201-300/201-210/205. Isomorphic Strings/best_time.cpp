class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int hash[256] = {0};
        bool ismap[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(hash[s[i]] == 0 && !ismap[t[i]]){
                hash[s[i]] = t[i];
                ismap[t[i]] = true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]] != t[i]) return false;
        }
        return true;
    }
};