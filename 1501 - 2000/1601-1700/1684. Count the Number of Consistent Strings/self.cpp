class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int res = 0;
        for(int ch: allowed) s.insert(ch);
        for(string& word: words) {
            bool isConsistent = true;
            for(char ch: word) {
                if(s.find(ch) == s.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) res++;
        }
        return res;
    }
};