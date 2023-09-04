class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        int alphaCount[26] = {0};
        for(char ch : magazine) {
            alphaCount[ch - 'a']++;
        }
        for(char ch : ransomNote) {
            if(alphaCount[ch - 'a']-- <= 0) return false;
        }
        return true;
    }
};