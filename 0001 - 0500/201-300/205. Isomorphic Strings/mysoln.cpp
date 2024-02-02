class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> charMapST;
        unordered_map<char, char> charMapTS;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (charMapST.find(c1)==charMapST.end() && charMapTS.find(c2)==charMapTS.end()) {
                charMapST[c1] = c2;
                charMapTS[c2] = c1;
            } 
            else if (charMapST[c1] != c2 || charMapTS[c2] != c1) return false;
        }
        return true;
    }
};