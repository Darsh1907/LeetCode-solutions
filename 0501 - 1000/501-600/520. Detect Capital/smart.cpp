class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        int small = 0;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(word[i]<='Z') cap++;
            else small++;
        }
        if(cap==n) return true;
        else if(small == n) return true;
        else if (small + 1 == n && word[0]<='Z') return true;
        return false;
    }
};