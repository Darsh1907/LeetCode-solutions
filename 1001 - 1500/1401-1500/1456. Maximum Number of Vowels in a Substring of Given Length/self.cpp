class Solution {
private:
    inline bool isVowel(char ch) {
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int en = 0, st = 0;
        int count = 0;
        while(1) {
            if(isVowel(s[en])) count++;
            if(en==(k-1)) break;
            en++;
        }
        int res = count;
        while(en < s.size()) {
            if(isVowel(s[st++])) count--;
            if(isVowel(s[++en])) count++;
            res = max(res, count);
        }
        return res;
    }
};