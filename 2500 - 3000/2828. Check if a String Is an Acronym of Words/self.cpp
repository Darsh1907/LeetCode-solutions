class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int words_size = words.size();
        if(words_size != s.size()) return false;
        for(int i=0; i<words.size(); i++){
            if(words[i][0] != s[i]) return false;
        }
        return true;
    }
};