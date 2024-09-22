class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s;
        for(string& str: bannedWords) s.insert(str);
        int count = 0;
        for(string& str: message) {
            auto fin = s.find(str);
            if(fin != s.end()) count++;
            if(count == 2) return true;
        }
        return false;
    }
};