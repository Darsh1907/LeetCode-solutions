class Solution {
public:
    char repeatedCharacter(string s) {
        set<int> visi;
        for(int i=0; i<s.size(); ++i){
            if(visi.find(s[i]) != visi.end()) return s[i];
            else visi.insert(s[i]);
        }
        return 'd';
    }
};