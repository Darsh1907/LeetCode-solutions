class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < 2; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] != s2[i+2] || s1[i+2] != s2[i]) return false; 
                else swap(s2[i], s2[i+2]);
            }
        }
        return s1 == s2;
    }
};